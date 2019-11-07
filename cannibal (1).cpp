#include<iostream>
#include<iomanip>
using std::cout;
int im = 3, ic = 3, i, fm = 0, fc = 0, status = 0, flag = 0, select = 0;
void display(char bpass1, char bpass2)
{
    cout << "\n\n\n";
    for (int i = 0; i < fm; i++) 
        cout << " M "; 
    for (int i = 0; i < fc; i++)
        cout << " C "; 

    if (flag == 0)
        cout << "     ~~~~~WATER~~~~~<B0(" << bpass1 << "," << bpass2 << ")AT>  ";
    else
        cout << "     <BO(" << bpass1 << "," << bpass2 << ")AT>~~~~~WATER~~~~~  ";
    for (int i = 0; i < im; i++)
        cout << " M ";
    for (int i = 0; i < ic; i++)
        cout << " C ";
}
int win()
{
    return (fc == 3 && fm == 3) ? 0 : 1;
}
void solution()
{
    while (win())
    {
        if (!flag)
        {
            switch (select)
            {
                case 1: display('C', ' ');
                        ic++;
                        break;
                case 2: display('C', 'M');
                        ic++; im++;    
                        break;   
            }
            
            if (((im - 2) >= ic && (fm + 2) >= fc) || (im - 2) == 0)
            {
                im = im - 2;
                select = 1;
                display('M', 'M');
                flag = 1;
            }
            else if ((ic - 2) < im && (fm == 0 || (fc + 2) <= fm) || im == 0)
            {
                ic = ic - 2;
                select = 2;
                display('C', 'C');
                flag = 1;
            }
   
            else if ((ic--) <= (im--) && (fm++) >= (fc++))
            {
                ic = ic - 1;
                im = im - 1;
                select = 3;
                display('M', 'C');
                flag = 1;
            }
        }
  
        else
        {
            switch (select)
            {
                case 1: display('M', 'M');
                        fm = fm + 2;
                        break;
                
                case 2: display('C', 'C');
                        fc = fc + 2;
                        break;   
                
                case 3: display('M', 'C');
                        fc = fc + 1;
                        fm = fm + 1;
                        break;
            }
   
            if (win())
            {
                if (((fc > 1 && fm == 0) || im == 0))
                {
                    fc--;
                    select = 1;
                    display('C', ' ');
                    flag = 0;
                }
                
                else if ((ic + 2) > im)
                {
                    fc--; fm--;
                    select = 2;
                    display('C', 'M');
                    flag = 0;
                }
            }
        }
    }
}
int main()
{
    cout << "MISSIONARIES AND CANNIBAL SOLUTION";
    display(' ', ' ');
    solution();
    display(' ', ' ');
    return 0;
}
/*output:
project-lab@projectlab-OptiPlex-380:~$ g++ cannibal.cpp
project-lab@projectlab-OptiPlex-380:~$ ./a.out
MISSIONARIES AND CANNIBAL SOLUTION


     ~~~~~WATER~~~~~<B0( , )AT>   M  M  M  C  C  C 


     ~~~~~WATER~~~~~<B0(C,C)AT>   M  M  M  C 


     <BO(C,C)AT>~~~~~WATER~~~~~   M  M  M  C 


 C      <BO(C, )AT>~~~~~WATER~~~~~   M  M  M  C 


 C      ~~~~~WATER~~~~~<B0(C, )AT>   M  M  M  C 


 C      ~~~~~WATER~~~~~<B0(C,C)AT>   M  M  M 


 C      <BO(C,C)AT>~~~~~WATER~~~~~   M  M  M 


 C  C      <BO(C, )AT>~~~~~WATER~~~~~   M  M  M 


 C  C      ~~~~~WATER~~~~~<B0(C, )AT>   M  M  M 


 C  C      ~~~~~WATER~~~~~<B0(M,M)AT>   M  C 


 C  C      <BO(M,M)AT>~~~~~WATER~~~~~   M  C 


 M  C      <BO(C,M)AT>~~~~~WATER~~~~~   M  C 


 M  C      ~~~~~WATER~~~~~<B0(C,M)AT>   M  C 


 M  C      ~~~~~WATER~~~~~<B0(M,M)AT>   C  C 


 M  C      <BO(M,M)AT>~~~~~WATER~~~~~   C  C 


 M  M  M      <BO(C, )AT>~~~~~WATER~~~~~   C  C 


 M  M  M      ~~~~~WATER~~~~~<B0(C, )AT>   C  C 


 M  M  M      ~~~~~WATER~~~~~<B0(C,C)AT>   C 


 M  M  M      <BO(C,C)AT>~~~~~WATER~~~~~   C 


 M  M  M  C      <BO(C, )AT>~~~~~WATER~~~~~   C 


 M  M  M  C      ~~~~~WATER~~~~~<B0(C, )AT>   C 


 M  M  M  C      ~~~~~WATER~~~~~<B0(C,C)AT>  


 M  M  M  C      <BO(C,C)AT>~~~~~WATER~~~~~  


 M  M  M  C  C  C      <BO( , )AT>~~~~~WATER~~~~~  project-lab@projectlab-OptiPlex-380:~$ 
*/
