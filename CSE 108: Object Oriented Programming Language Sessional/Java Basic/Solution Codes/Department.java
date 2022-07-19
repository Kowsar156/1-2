public class Department {

    private int id;
    private String name;
    private Employee [] employees;
    private int employeeCount;
    private double departmentSalary;
    public static int DepartmentCount = 0;
    public static Department [] departments = new Department[20];

    public Department(int id, String name) {
        this.id = id;
        this.name = name;
        this.employees = new Employee[10];
        this.employeeCount = 0;
        this.departmentSalary = 0.0;
        departments[DepartmentCount++] = this;
    }

    public void addEmployee(Employee a){
        employees[employeeCount++] = a;
        this.departmentSalary += a.getSalary();
    }

    public double getDepartmentSalary(){
        return departmentSalary;
    }

    Employee getMaxSalaryEmployee(){
        double MaxSalary = employees[0].getSalary();
        int index = 0;
        for(int i=1;i<this.employeeCount;i++){
            if(employees[i].getSalary()>MaxSalary){
                MaxSalary = employees[i].getSalary();
                index = i;
            }
        }
        return employees[index];
    }

    public static double getTotalSalary(){
        double TotalSalary = departments[0].departmentSalary;
        for(int i=1;i<2;i++){
            TotalSalary += departments[i].departmentSalary;
        }
        return TotalSalary;
    }

}