//Game for Kids
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>      //open file for reading, writing, or both
using namespace std;

//Function Prototype
double Question1();
double Question2();
double Question3();
double Question4();
double Question5();
double Question6();
void SaveName(string &name);
void ShowScore(string name, int totalscore);
void SavetoFile(string name, int totalscore);

//function.Question1
double Question1() 
{   
    int answerQ1;
    int Q1score;

    cout << "\nQuestion 1" << endl;
    cout << "What is the total of 5+4+3+8?" << endl;
    cin >> answerQ1;

    if (answerQ1 == 20) {
        cout << "Your answer is correct." << endl;
        Q1score = 10;
    }
    else {
        cout << "Your answer is wrong." << endl;
        Q1score = 0;
    }
    return Q1score;
}

//function.Question2
double Question2() 
{   
    char answerQ2;
    int Q2score;
    cout << "\nQuestion 2" << endl;
    cout << "Daddy and Mommy is also Father and Mother";
    cout << "\n(Please enter 'T' for True or 'F' for False)" << endl;
    cin >> answerQ2;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');    // Consume the newline character

    if (answerQ2 == 'T' || answerQ2 == 't') {
        cout << "Well done, your answer is correct." << endl;
        Q2score = 20;
    }
    else{
        cout << "Your answer is wrong." << endl;
        Q2score = 0;
    }
    return Q2score;
}

//function.Question3
double Question3()
{   
    string answerQ3;
    int Q3score;

    bool correct = false;       //set false default

    do {
        cout << "\nQuestion 3" << endl;
        cout << "What animal sound as 'Meow Meow~~'? " << endl;
        cout << "(This question will loop till get correct answer.)" << endl;
        cin >> answerQ3;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // check answer is correct or not
        if (answerQ3 == "cat" || answerQ3 == "Cat") {
            correct = true;
        }
        else {
            cout << "Incorrect! Try again.\n";
        }
    } while (!correct);         //when enter answer correct

    if (correct = true) {
        Q3score = 20;
        cout << "Well done, you entered the correct answer!" << endl;
    }
    else {
        Q3score = 0;
    }

    return Q3score;
}

//function.Question4
double Question4()
{
    int Q4score;
    string answerQ4;
    bool correct = false;

    while (!correct) {  //Continue asking until correct
        cout << "\nQuestion 4" << endl;
        cout << "How to spell 'Candy' ?" << endl;
        cout << "(This question will loop till get correct answer.)" << endl;
        cin >> answerQ4;

        char correctAnswer[] = "Candy";
        bool match = true;

        for (int i = 0; i < 5; i++) {  //to compare each letter
            if (answerQ4[i] != correctAnswer[i]) {
                match = false;
                break;
            }
        }

        if (match) {     //if matches than its correct
            cout << "You are correct!! " << endl;
            correct = true;
            Q4score = 10;
        }
        else {   // else it rerun the command prompt again
            cout << "That is not correct.Try again. " << endl;
            Q4score = 0;
        }
    }
    return Q4score;
}

//function.Question5
double Question5()
{
    int Q5score;
    string answerQ5;

    while (true) {  // Program runs indefinitely until answer is exact
        cout << "\nQuestion 5" << endl;
        cout << "What do you call your father's father? " << endl;
        cout << "(This question will loop till get correct answer.)" << endl;
        cin >> answerQ5;

        if (answerQ5 == "grandfather" || answerQ5 == "Grandfather") {    //to check if the answer is the same
            cout << "You are correct!! " << endl;
            Q5score = 20;
            break;  //Answer is correct and loop will stop
        }
        else {
            cout << "Your answer is not correct!! Please try again. " << endl; //The loop will continue till the answer is correct
        }
    }
    return Q5score;
}

//function.Question6
double Question6()
{
    int Q6score;
    double milkprice, chocolateprice, sstcharge, totalprice, answerQ6;

    cout << "\nQuestion 6" << endl;
    cout << "You buy a bottle of milk and a bar of chocolate from a small supermarket." << endl;
    cout << "Calculate the total price after adding 6% SST." << endl;

    //Input validation for milkprice
    while (true) {
        cout << "\nEnter the price of milk: RM";
        if (cin >> milkprice) {
            break;
        }
        else {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear(); // clear error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore rest of line
        }
    }

    //Input validation for chocolateprice
    while (true) {
        cout << "Enter the price of chocolate: RM";
        if (cin >> chocolateprice) {
            break;
        }
        else {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }


    sstcharge = (milkprice + chocolateprice)*0.06;
    totalprice = milkprice + chocolateprice + sstcharge;


    //prompt user to calculate price after adding SST
    cout << "\nYou entered the price of milk as RM" << milkprice << " and the price of chocolate as RM" << chocolateprice << endl;
    cout << "There is a 6% SST that needs to be added to the payment, how much do you need to pay?" << endl;
    cout << "RM";

    //Input validation for answerQ6
    while (true) {
        if (cin >> answerQ6) {
            break;
        }
        else {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }


    if (answerQ6 == totalprice) {
        cout << "\nYour answer is correct, you need to paid RM" << fixed << setprecision(2) << totalprice << "." << endl;
        Q6score = 20;
    }
    else {
        cout << "\nYour answer is wrong, the total is RM" << totalprice << "." << endl;
        cout << "You need to pay RM" << fixed << setprecision(2) << totalprice << "." << endl;
        Q6score = 0;
    }

    return Q6score;
}

//function.Save your name
void SaveName(string &name) {
    cout << "\nHello may I know your name?" << endl;
    cin.ignore();                                       //ignore the newline character left in the input buffer
    getline(cin, name);
    cout << "Your name has been saved!" << endl;
}

//function.Show Score
void ShowScore(string name, int totalscore)
{   
    cout << "Hello, " << name << "! Your total score is " << totalscore << "%.\n";
}

//function.SavetoFile
void SavetoFile(string name, int totalscore)
{
    ofstream outfile;
    outfile.open("Saved Score.txt", ios::out);

    if (!outfile) 
    {
        cout << "File could not be opened!";
        return;
    }

    outfile << "Hello, " << name << "! Your total score is " << totalscore << "%.\n";

    outfile.close();
    cout << "File saved." << endl;

    return;
}

//main Function
int main()
{
    int choice;
    string name;
    int Q1score = 0, Q2score = 0, Q3score = 0, Q4score = 0, Q5score = 0, Q6score = 0;

    //Option list
    do {                                                                
        cout << endl;
        cout << "   Welcome to Games for Kids!   " << endl;
        cout << "--------------------------------" << endl;
        cout << "     (Enter number of below)    " << endl;
        cout << "1. Question 1" << endl;
        cout << "2. Question 2" << endl;
        cout << "3. Question 3" << endl;
        cout << "4. Question 4" << endl;
        cout << "5. Question 5" << endl;
        cout << "6. Question 6" << endl;
        cout << "7. Save your name" << endl;
        cout << "8. Show your score" << endl;
        cout << "9. Save your score to File" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        //choices
        switch (choice) {
        case 1:
            Q1score = Question1();
            break;
        case 2:
            Q2score = Question2();
            break;
        case 3:
            Q3score = Question3();
            break;
        case 4:
            Q4score = Question4();
            break;
        case 5:
            Q5score = Question5();
            break;
        case 6:
            Q6score = Question6();
            break;
        case 7:
            SaveName(name);
            break;
        case 8:
            ShowScore(name, Q1score + Q2score + Q3score + Q4score + Q5score + Q6score);
            break;
        case 9:
            SavetoFile(name, Q1score + Q2score + Q3score + Q4score + Q5score + Q6score);
            break;
        }
    } while (choice!= 0);

    cout << "\nBye bye";

    return 0;
}