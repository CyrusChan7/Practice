/* using stdio.h instead of iostream because at the time of creation
I'm still not familiar with iostream, cout, and namespace std
*/

#include <stdio.h>

class Student {
    private:
        int gradePercentage = 0;
    public:
        Student(){                  // constructor
            gradePercentage = 86;
        }

        void printHelloWorld(){
            printf("Hello world!\n");
        }
        int getGradePercentage(){
            return gradePercentage;
        }
        void editGradePercentage(int newValue){
            gradePercentage = newValue;
        }
};

int main(){

    Student Cyrus;
    Cyrus.printHelloWorld();

    printf("Cyrus' grade percentage is %d\n", Cyrus.getGradePercentage());

    Cyrus.editGradePercentage(90);
    printf("Cyrus' new grade percentage is %d\n", Cyrus.getGradePercentage());

    return 0;
}
