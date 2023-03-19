#include <iostream>
using namespace std;
// factory employess
int main()
{

  const int size = 1000;
  string names[size];
  int ages[size];
  double salaries[size];
  char genders[size];
  int added = 0;

  while (true)
  {
    int choice = -1;
    cout << "\n Enter your choice\n";
    cout << " 1)add new empployes \n";
    cout << " 2)print all employes \n";
    cout << " 3)delete by age \n";
    cout << " 4)update salary by name \n";
    cin >> choice;

    if (choice < 1 && choice > 4)
    {
      cout << "invaild choice try again \n";
      continue;
    }

    if (choice == 1)
    {
      cout << "Enter Name\n";
      cin >> names[added];
      cout << "Enter age\n";
      cin >> ages[added];
      cout << "Enter salary\n";
      cin >> salaries[added];
      cout << "Enter gender (M/F)\n";
      cin >> genders[added];
      ++added;
    }
    else if (choice == 2)
    {
      for (int i = 0; i < added; ++i)
      {
        cout << names[i] << " " << ages[i] << " " << salaries[i] << " " << genders[i] << "\n";
      }
    }
    else if (choice == 3)
    {
      cout << "Enter your start and end \n";
      int start, end;
      cin >> start >> end;
      for (int i = 0; i < added; ++i)
      {

        if (start <= ages[i] && ages[i] <= end)
        {
          ages[i] = -1; // lazy delete
        }
      }
    }
    else
    {
      bool is_Found = false;
      string name;
      int salary;
      cout << "Enter the employer name \n";
      cin >> name;
      cout << "Enter the new salary \n";
      cin >> salary;
      for (int i = 0; i < added; ++i)
      {
        if (ages[i] != -1 && names[i] == name)
        {
          is_Found = true;
          salaries[i] = salary;
          cout << salary;
          break;
        }
      }

      if (!is_Found)
      {
        cout << "no employee with this name \n";
      }
    }
  }

  return 0;
}