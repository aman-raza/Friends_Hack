#include <iostream>
#include <fstream>
using namespace std;
const char* file1 = "Source1.txt";
const char* file2 = "Source2.txt";
const char* file3 = "Target.txt";
int main()
{
ifstream inputfile1, inputfile2;
ofstream outfile;
inputfile1.open(file1);
inputfile2.open(file2);
if (inputfile1 == NULL || inputfile2 == NULL)
{
perror("Could not open the files");
cout << "Press any key to exit" << endl;
getchar();
exit(0);
}
outfile.open(file3);
if (!outfile)
{
perror("Could not open the file");
cout << "Press any key to exit" << endl;
getchar();
exit(0);
}
int arr1[5], arr2[5];
while (inputfile1.read((char*)&arr1, sizeof(arr1)) != NULL)
{
cout << "Data received from Source1.txt" << endl;
}
for (int i = 0; i < 5; i++)
{
cout << arr1[i] << " ";
}
cout << endl;
while (inputfile2.read((char*)&arr2, sizeof(arr2)) != NULL)
{
cout << "Data recieved from Source2.txt" << endl;
}
for (int i = 0; i < 5; i++)
{
cout << arr2[i] << " ";
}
cout << endl;
int arr[10], i = 0, j = 0, k = 0;
fill(arr, arr + 10, 0);
while (i < 5 && j < 5)
{
if (arr1[i] < arr2[j])
{
arr[k++] = arr1[i++];
}
else
{
arr[k++] = arr2[j++];
}
}
while (i < 5)
{
arr[k++] = arr1[i++];
}
while (j != 5)
{
arr[k++] = arr[j++];
}
cout << "The Merged Array that will be stored in Target.txt (in binary form): " << endl;
for (i = 0; i < 10; i++)
cout << arr[i] << " ";
cout << endl;
outfile.write((char*)&arr, sizeof(arr));
return 0;
}

