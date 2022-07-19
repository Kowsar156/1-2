# include <iostream>
using namespace std;

# define INTEGER 1
# define INT_ARRAY 2
# define INT_MATRIX 3

// Container class can contain an integer, or an integer array or an integer matrix, but exactly one of them
class Container{
    // Do not add any additional member variable
    int *value;
    int *valueArray;
    int **valueMatrix;
    int firstDim, secondDim;    // the dimensions of array/matrix, in case of single integer, both should be 0
    int storedType;

    // the following is a private method, not needed from outside
    void reset(){
        if (value != NULL){
            delete value;
        }
        else{
        	value=NULL;
		}
        if (valueArray != NULL){
            delete [] valueArray;
        }
        else{
        	valueArray=NULL;
		}
        if (valueMatrix != NULL){
            for(int i=0;i<firstDim;i++){
				delete [] (valueMatrix+i);
			}
			delete [] valueMatrix;
        }
        else{
        	valueMatrix=NULL;
		}
        firstDim = 0;
        secondDim = 0;
        storedType = -1;
    }

public:
    // do not write any additional public method except for those which you are asked to, according to the comments
    Container(){
        cout << "Constructing Container with empty parameter" << endl;
        cout << "___________________________________________" << endl;
        value = NULL;
        valueArray = NULL;
        valueMatrix = NULL;
        firstDim = 0;
        secondDim = 0;
        storedType = -1;
    }

    Container (int val){
        cout << "Constructing Container with a single integer parameter" << endl;
        cout << "______________________________________________________" << endl;
        value=new int (val);
        valueArray=NULL;
        valueMatrix=NULL;
        firstDim = 0;
        secondDim = 0;
        storedType = INTEGER;
    }

    Container (int *valArr, int len){
        cout << "Constructing Container with integer array parameter" << endl;
        cout << "___________________________________________________" << endl;
        valueArray=new int [len];
        for(int i=0;i<len;i++){
        	valueArray[i]=valArr[i];
		}
		value=NULL;
		valueMatrix=NULL;
        firstDim = len;
        secondDim = 0;
        storedType = INT_ARRAY;
    }

    Container (int **valMat, int r, int c){
        cout << "Constructing Container with integer matrix parameter" << endl;
        cout << "____________________________________________________" << endl;
        valueMatrix=new int *[r];
        for(int i=0;i<r;i++){
        	valueMatrix[i]=new int [c];
        	for(int j=0;j<c;j++){
        		valueMatrix[i][j]=valMat[i][j];
			}
		}
		value=NULL;
		valueArray=NULL;
		firstDim=r;
		secondDim=c;
		storedType=INT_MATRIX;
    }

    Container(const Container &a)
	{
		cout << "Calling copy constructor of Container" << endl;
    	cout << "_____________________________________" << endl;
		if(storedType==INTEGER){
			value=a.value;
		}
		else if(storedType==INT_ARRAY){
			int i;
			valueArray=new int [a.firstDim];
			for(i=0;i<a.firstDim;i++){
				valueArray[i]=a.valueArray[i];
			}
		}
		else if(storedType==INT_MATRIX){
			int i,j;
			valueMatrix=new int *[a.firstDim];
			for(i=0;i<a.firstDim;i++){
				valueMatrix[i]=new int [a.secondDim];
				for(j=0;j<a.secondDim;j++){
					valueMatrix[i][j]=a.valueMatrix[i][j]; 
				}
			}
		}
	}


    void setItem (int *val){
        reset();
        value=new int (*val);
        valueArray=NULL;
        valueMatrix=NULL;
        firstDim = 0;
        secondDim = 0;
        storedType = INTEGER;
    }

    void setItem (int *valArr, int len){
		reset();
		valueArray=new int [len];
        for(int i=0;i<len;i++){
        	valueArray[i]=valArr[i];
		}
		value=NULL;
		valueMatrix=NULL;
        firstDim = len;
        secondDim = 0;
        storedType = INT_ARRAY;
	}

    void setItem (int **valMat, int r, int c){
		reset();
		valueMatrix=new int *[r];
        for(int i=0;i<r;i++){
        	valueMatrix[i]=new int [c];
        	for(int j=0;j<c;j++){
        		valueMatrix[i][j]=valMat[i][j];
			}
		}
		value=NULL;
		valueArray=NULL;
		firstDim=r;
		secondDim=c;
		storedType=INT_MATRIX;
	}
	
	
    void * getItem(){
        if (value != NULL) return value;
        if (valueArray != NULL) return valueArray;
        if (valueMatrix != NULL) return valueMatrix;
        return NULL;
    }

    int getFirstDim(){
        return firstDim;
    }

    int getSecondDim(){
        return secondDim;
    }

    int getStoredType(){
        return storedType;
    }

    void print(){
        if (value != NULL){
            cout << "There is only an integer value in the container object" << endl;
            cout << "The value is: " << *value << endl;
        }
        else if (valueArray != NULL){
            cout << "There is an integer array in the container object" << endl;
            cout << "The values stored in the array are:" << endl;
            for (int i=0; i<firstDim; i++){
                cout << valueArray[i] << " ";
            }
            cout << endl;
        }
        else if (valueMatrix != NULL){
            cout << "There is an integer matrix in the container object" << endl;
            cout << "The values stored in the matrix are:" << endl;
            for (int i=0; i<firstDim; i++){
                for (int j=0; j<secondDim; j++){
                    cout << valueMatrix[i][j] << " ";
                }
                cout << endl;
            }
        }
        else{
            cout << "The object has no elements" << endl;
        }
    }
    
    Container& promote(){
    	if(valueArray==NULL&&valueMatrix==NULL){
    		valueArray = new int [10];
    		valueArray[0] = *value; 
    		return *this;
		}
		else if(value==NULL&&valueMatrix==NULL){
			valueMatrix = new int* [firstDim];
			for(int i=0;i<firstDim;i++){
				valueMatrix[i] = new int [10];
				valueMatrix[i][0] = valueArray[i];
			}
			return *this;
		}
	}

    ~Container(){
        if (value != NULL){
            cout << "Freeing allocated memory for a single integer" << endl;
            delete value;
        }
        if (valueArray != NULL){
            cout << "Freeing allocated memory for integer array" << endl;
            delete [] valueArray;
        }
        if (valueMatrix != NULL){
            cout << "Freeing allocated memory for integer matrix" << endl;
            for(int i=0;i<firstDim;i++){
				delete [] (valueMatrix+i);
			}
			delete [] valueMatrix;
        }
        firstDim = 0;
        secondDim = 0;
        storedType = -1;
        cout << "_____________________" << endl;
        cout << "Destructing Container" << endl;
    }
};

int main(){
	Container b(100);
	int *arr = new int[3];
	arr[0] = 10;
	arr[1] = 20;
	arr[2] = 30;
	Container c(arr, 3);
	b.print();
		// b contains a single integer, 100
	b.promote().print();
			// the returned object contains an integer array with a single element, 200
	b.print();
	// b contains an integer array with a single element, 100
	c.print();
	// c contains an integer array with elements 10, 20, 30
	c.promote().print();
	// the returned object contains an integer matrix with a single row. The elements of the row are 30, 60, 90
	c.print();
	// c contains an integer matrix with a single row. The elements of the row are 10, 20, 30
	return 0;
}
