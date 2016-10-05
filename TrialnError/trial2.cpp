/*
 * trial2.cpp
 *
 *  Created on: Sep 13, 2014
 *      Author: sandyarathidas
 */

#include <iostream>
using namespace std;

void intro();
void input();

void input(char[]);
void output(char[]);
void hex_sum(char[], char[], char[]);

int main()
{
    char answer;

    intro();

    do
    {
        input();

        cout << endl << endl << "Do you wish to convert another hexadecimal number? (y/n) \n";
        cin >> answer;

    } while(answer == 'y' || answer == 'Y');

    cout << "Good-bye! \n";

    return 0;
}

void intro()
{
    cout << "Intro." << endl;
}

void input()
{
    char number_1[10] = {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'};
    char number_2[10] = {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'};
    cout<<number_2;
    char sum[10] = {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'};

    cout<<"Printing sum :"<<sum<<endl;
    cout << "Enter the first hexadecimal number \n";
    input(number_1);
    cout << endl;

    cout << "Enter the second hexadecimal number \n";
    input(number_2);
    cout << endl;

    hex_sum(number_1, number_2, sum);;

    cout << "The addition of the two hexadecimal numbers is \n";
    output(sum);
}

void input(char number[])
{
    int i = 0;
    char c = '0', tmp;

    while(c != 'q') //this is my problem right here!
    {
        cin >> c;
        number[i] = c;
        i++;
    }

    number[--i] = '0';
    cout<<"\n printing the number"<<number[i];

    for(int k = 0; k < i/2; k++)
    {
        tmp = number[k];
        number[k] = number[i - 1 - k];
        number[i - 1 - k] = tmp;
    }
}

void output(char number[])
{
    for(int i = 9; i >= 0; i--)
    {
        cout << number[i];
    }
}

void hex_sum(char number_1[], char number_2[], char sum[])
{
    int x, y, s, carry = 0, next_carry = 0;

    for(int i = 0; i < 10; i++)
    {
        if('0' <= number_1[i] && number_1[i] < '0' + 10)
            x = number_1[i] - '0';

        else
            x = number_1[i] - 'A' + 10;

        if('0' <= number_2[i] && number_2[i] < '0' + 10)
            y = number_2[i] - '0';

        else
            y = number_2[i] - 'A' + 10;


        carry = next_carry;

        s = (x + y + carry) % 16;
        next_carry = (x + y + carry) / 16; //converts the number back to hex

        if(0 <= s && s < 10)
            sum[i] = char('0' + s);

        else if(10 <= s && s < 16)
            sum[i] = char('A' + s - 10);

        else
            cout << "Invalid input \n";
    }

    if(1 == carry && 1 == next_carry)
        cout << "Overflow! \a \n";
}





