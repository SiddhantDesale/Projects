import java.util.*;

class Student
{
    public int Rno;
    public String Name;
    public int Age;
    public String City;
    public int Marks;

    public static int Generator;

    static
    {
        Generator = 0;
    }

    public Student(String str1, int X, String str2, int Y)
    {
        this.Rno = ++Generator;
        this.Name = str1;
        this.City = str2;
        this.Age = X;
        this.Marks = Y;
    }

    public void Display()
    {
        System.out.println("--------------------------------------------------");
        System.out.printf("| %-4d | %-10s | %-4d | %-10s | %-6d |\n",Rno,Name,Age,City,Marks);
        System.out.println("--------------------------------------------------");
    }
}

class DBMS
{
    public LinkedList <Student> lobj;

    public DBMS()
    {
        lobj = new LinkedList <Student> ();
    }

    public void StartDBMS()
    {
        System.out.println("\nSiddhant's DBMS started successfully...");
        System.out.println("Table Schema created successfully...\n");
        
        String Query;
        String Token[];

        Scanner sobj = new Scanner(System.in);
        int TokensCount = 0;

        while(true)
        {
            System.out.print("Siddhant's DBMS : ");
            Query = sobj.nextLine();

            Token = Query.split(" ");

            TokensCount = Token.length;

            if(TokensCount == 1)
            {
                if("exit".equals(Token[0]))
                {
                    System.out.println("Thank you for using Siddhant's DBMS...");
                    break;
                }
            }
            else if(TokensCount == 2)
            {}
            else if(TokensCount == 3)
            {}
            else if(TokensCount == 4)
            {
                if("select".equals(Token[0]))
                {
                    SelectFrom();
                }
            }
            else if(TokensCount == 5)
            {
                if("select".equals(Token[0]))
                {
                    if("MAX".equals(Token[1]))
                    {
                        System.out.println("Maximum marks are : "+Aggregate_Max());
                    }
                    else if("MIN".equals(Token[1]))
                    {
                        System.out.println("Minimum marks are : "+Aggregate_Min());
                    }
                    else if("AVG".equals(Token[1]))
                    {
                        System.out.println("Average marks are : "+Aggregate_Avg());
                    }
                    else if("SUM".equals(Token[1]))
                    {
                        System.out.println("Sum of marks is : "+Aggregate_Sum());
                    }
                    else if("Count".equals(Token[1]))
                    {
                        System.out.println("Number of records are :"+Count());
                    }
                }
            }
            else if(TokensCount == 6)
            {}
            else if(TokensCount == 7)
            {
                if("delete".equals(Token[0]))
                {
                    DeleteFrom(Integer.parseInt(Token[6]));
                }
            }
            else if(TokensCount == 8)
            {
                if("insert".equals(Token[0]))
                {
                    InsertIntoTable(Token[4], Integer.parseInt(Token[5]), Token[6], Integer.parseInt(Token[7]));
                }
                else if("select".equals(Token[0]))
                {
                    if("Rno".equals(Token[5]))
                    {
                        SelectFromRno(Integer.parseInt(Token[7]));
                    }
                    else if("Name".equals(Token[5]))
                    {
                        SelectFromName(Token[7]);
                    }
                    else if("Age".equals(Token[5]))
                    {
                        SelectFromAge(Integer.parseInt(Token[7]));
                    }
                    else if("City".equals(Token[5]))
                    {
                        SelectFromCity(Token[7]);
                    }
                    else if("Marks".equals(Token[5]))
                    {
                        SelectFromMarks(Integer.parseInt(Token[7]));
                    }
                }
            }
            else if(TokensCount == 10)
            {
                if("update".equals(Token[0]))
                {
                    if(("City".equals(Token[3])) && ("Rno".equals(Token[7])))
                    {
                        UpdateFrom(Token[5], Integer.parseInt(Token[9]));
                    }
                }
            }
            else if(TokensCount == 12)
            {
                if("select".equals(Token[0]))
                {
                    if(("City".equals(Token[5])) && "AND".equals(Token[8]))
                    {
                        if("Marks".equals(Token[9]))
                        {
                            SelectFromCity_Marks(Token[7], Integer.parseInt(Token[11]), Token[10]);
                        }
                        else if("Age".equals(Token[9]))
                        {
                            SelectFromCity_Age(Token[7], Integer.parseInt(Token[11]));
                        }
                    }
                }
            }
        }

    }

    //insert into student values(_____,_____,_____);
    public void InsertIntoTable(String name, int age, String city, int marks)
    {
        Student sobj = new Student(name,age,city,marks);
        lobj.add(sobj);
    }

    //select * from student
    public void SelectFrom()
    {
        System.out.println("Records from the student table are :");
        System.out.println("--------------------------------------------------");
        System.out.printf("| %-4s | %-10s | %-4s | %-10s | %-6s |\n","Rno","Name","Age","City","Marks");
        System.out.println("--------------------------------------------------");

        for(Student sref : lobj)
        {
            sref.Display();
        }
    }

    // select * from student where Rno = 11
    public void SelectFromRno(int no)
    {
        for(Student sref : lobj)
        {
            if(sref.Rno == no)
            {
                sref.Display();
                break;
            }
        }
    }

    // select * from student where Name = Rahul
    public void SelectFromName(String str)
    {
        for(Student sref : lobj)
        {
            if(str.equals(sref.Name))
            {
                sref.Display();
            }
        }
    }

    // select * from student where Age = 23
    public void SelectFromAge(int no)
    {
        for(Student sref : lobj)
        {
            if(sref.Age == no)
            {
                sref.Display();
            }
        }
    }

    // select * from student where City = 'Pune'
    public void SelectFromCity(String str)
    {
        for(Student sref : lobj)
        {
            if(str.equals(sref.City))
            {
                sref.Display();
            }
        }
    }

    // select * from student where Marks = 98
    public void SelectFromMarks(int no)
    {
        for(Student sref : lobj)
        {
            if(sref.Marks == no)
            {
                sref.Display();
            }
        }
    }

    // select * from student where city = 'pune' AND marks < 98
    public void SelectFromCity_Marks(String str1, int no, String str2)
    {
        for(Student sref : lobj)
        {
            if((str1.equals(sref.City)) && (sref.Marks == no) && (str2.equals("=")))
            {
                sref.Display();
            }
            else if((str1.equals(sref.City)) && (sref.Marks < no) && (str2.equals("<")))
            {
                sref.Display();
            }
            else if((str1.equals(sref.City)) && (sref.Marks > no) && (str2.equals(">")))
            {
                sref.Display();
            }
        }
    }

    // select * from student where city = 'Pune' AND Age = 24
    public void SelectFromCity_Age(String str1, int no)
    {
        for(Student sref : lobj)
        {
            if((str1.equals(sref.City)) && (sref.Age == no))
            {
                sref.Display();
            }
        }
    }

    //select Count(name) from student
    public int Count()
    {
        int iCount = 0;

        for(Student sref : lobj)
        {
            iCount++;
        }
        return iCount;
    }

    //select MAX(marks) from student
    public int Aggregate_Max()
    {
        int iMax = 0;
        for(Student sref : lobj)
        {
            if(sref.Marks > iMax)
            {
                iMax = sref.Marks;
            }
        }
        return iMax;
    }

    //select MIN(marks) from student
    public int Aggregate_Min()
    {
        Student temp = lobj.getFirst();
        int iMin = temp.Marks;

        for(Student sref : lobj)
        {
            if(sref.Marks < iMin)
            {
                iMin = sref.Marks;
            }
        }
        return iMin;
    }

    //select SUM(marks) from student
    public int Aggregate_Sum()
    {
        int iSum = 0;

        for(Student sref : lobj)
        {
            iSum = iSum + sref.Marks;
        }
        return iSum;
    }

    //select Average(marks) from student
    public double Aggregate_Avg()
    {
        double dSum = 0.0;

        for(Student sref : lobj)
        {
            dSum = dSum + sref.Marks;
        }
        return (dSum / (lobj.size()));
    }

    //update student set city = 'pune' where rno = 2
    public void UpdateFrom(String str, int no)
    {
        for(Student sref : lobj)
        {
            if(sref.Rno == no)
            {
                sref.City = str;
                break;
            }
        }
    }

    //delete from student where Rno = 2
    public void DeleteFrom(int no)
    {
        int i = 0;

        for(Student sref : lobj)
        {
            if(sref.Rno == no)
            {
                lobj.remove(i);
                break;
            }
            i++;
        }
    }
}

class Project_DBMS
{
    public static void main(String arg[])
    {
        DBMS obj = new DBMS();
        obj.StartDBMS();
    }
}