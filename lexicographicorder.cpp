#include <iostream>
using namespace std;


int compare(int left[], int right[], int sleft, int sright){
    // returns equals = 0, lower = 1, higher = 2
	int result = 0;

    for(int i = 0; i < sleft; i++)
    {
    	if ((sleft>sright) && (i == sright))
    	{
    		result = 2;
    		break;
    	}
    	if (left[i]>right[i])
    	{
    		result = 2;
    		break;
    	}
    	else if(left[i]<right[i])
		{
			result = 1;
			break;
		}
    }

    if((sleft<sright) && (result == 0))
    {
    	result = 1;
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
