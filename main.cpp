#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void meat(bool yesQues[], string input1, bool yesQues2[], bool individualYes[]);

void evaluate(bool yesQues[], int& runSum, bool yesQues2[], int& runSum2);

int main()
{
  ifstream inputObject1{"input.txt"};
  string input1{};

  bool yesQues[26]{}; //Array holds boolean value for every yes answer in the group

  bool yesQues2[26]{}; //yesQues2 starts at all yeses, and get's eliminated if not everyone in group says yes
  for(int i=0; i<26; ++i)
  {
    yesQues2[i]=true;
  }

  bool individualYes[26]{}; //keeps track of what an individual says yes to

  int runSum{0}; //Sum of # of yes answers per group
  int runSum2{0};

  while(getline(inputObject1, input1))
  {
    if(input1.empty()) //if empty, do what you need to do
    {
      evaluate(yesQues, runSum, yesQues2, runSum2);
    }
    else //if line contains information, do what you need to do
    {
      meat(yesQues, input1, yesQues2, individualYes);
    }
  }
  evaluate(yesQues, runSum, yesQues2, runSum2); //MUST EVALUATE 1 MORE TIME, NO NEWLINE AT END

  cout << runSum << endl;
  cout << runSum2 << endl;

  return 0;
}

//Sets true values in yesQues
void meat(bool yesQues[], string input1, bool yesQues2[], bool individualYes[])
{
  for(int i=0; i<input1.size(); ++i) //goes through each char in input1
  {
    for(int j=97; j<123; ++j) //compares char to a-z
    {
      if(input1[i]==j)
      {
        yesQues[j-97]=true;
        individualYes[j-97]=true;
      }
    }
  }

  for(int i=0; i<26; ++i) //Set's yesQues2 right & reset's individualYes
  {
    if(!individualYes[i])
    {
      yesQues2[i]=false;
    }
    individualYes[i]=false;
  }
}

void evaluate(bool yesQues[], int& runSum, bool yesQues2[], int& runSum2)//need to evaluate every new line and ONCE AT THE END
{
  int sum{0};
  int sum2{0};
  for(int i=0; i<26; ++i)
  {
    if(yesQues[i])
    {
      ++sum;
    }
    if(yesQues2[i])
    {
      ++sum2;
    }
    yesQues[i]=false;
    yesQues2[i]=true;
  }
  runSum+=sum;
  runSum2+=sum2;
}