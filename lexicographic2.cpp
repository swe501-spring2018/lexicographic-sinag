#include <iostream>
#include <sstream>
using namespace std;

string int_array_to_string(int int_array[], int size_of_array) {
  ostringstream oss("");
  for (int temp = 0; temp < size_of_array; temp++)
    oss << int_array[temp];
  return oss.str();
}

int compare(int left[], int right[], int sleft, int sright){
    // returns equals = 0, lower = 1, higher = 2
	int result = 0;
	string strleft = int_array_to_string(left,sleft);
	string strright = int_array_to_string(right,sright);

	if(strleft<strright)
	{
		result = 1;
	}
	else
	{
		if (strleft>strright)
		{
			result = 2;
		}
		else
		{
			result = 0;
		}
	}

    return result;
}

int main() {
    int nLists;
    cin >> nLists;
    int *List[nLists];
    int Sizes[nLists];

    for(int i=0; i < nLists; i++)
    {
    	int size;
    	cin >> size;
    	Sizes[i] = size;
    	List[i] = new int[size];
    	for(int j = 0; j < size; j++)
    	{
    		cin >> List[i][j];
    	}
    }

    cout << "Print original input" << endl;
    for(int i=0; i<nLists; i++)
    {
    	for(int j=0; j<Sizes[i]; j++)
    	{
    		cout << List[i][j] << " ";
    	}
    	cout << endl;
    }

    int swaps = 1;
    while(swaps>0)
    {
    	swaps = 0;
        for(int i=0; i<nLists-1; i++)
        {
        	int res = compare(List[i],List[i+1],Sizes[i],Sizes[i+1]);
        	if (res == 2)
        	{
        		int* tmpData = List[i];
        		List[i] = List[i+1];
        		List[i+1] = tmpData;
        		int tmpSize = Sizes[i];
        		Sizes[i] = Sizes[i+1];
        		Sizes[i+1] = tmpSize;
        		swaps++;
        	}
        }
    }

    cout << "Print sorted output" << endl;
    for(int i=0; i<nLists; i++)
    {
    	for(int j=0; j<Sizes[i]; j++)
    	{
    		cout << List[i][j] << " ";
    	}
    	cout << endl;
    }

	return 0;
}
