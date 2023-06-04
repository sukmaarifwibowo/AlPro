#include <iostream>
using namespace std;
void merge(int arr[], int left[], int leftSize, int right[], int rightSize)
{
    int i = 0, j = 0, k = 0;
    while (i < leftSize && j < rightSize)
    {
        if (left[i] < right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < leftSize)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < rightSize)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int n)
{
    if (n < 2)
    {
        return;
    }

    int mid = n / 2;
    int left[mid];
    int right[n - mid];

    for (int i = 0; i < mid; i++)
    {
        left[i] = arr[i];
    }

    for (int i = mid; i < n; i++)
    {
        right[i - mid] = arr[i];
    }

    mergeSort(left, mid);
    mergeSort(right, n - mid);
    merge(arr, left, mid, right, n - mid);
}


int binarySearch(int arr[], int n, int cari)
{
    int left = 0;
    int right = n - 1;
    int middle = 0;
    while (left<=right)
    {
        middle = (left + right) / 2;
        if (arr[middle] == cari)
            return middle;
        else if (cari < arr[middle])
            right = middle - 1;
        else
            left = middle + 1;
    }
    return -1;
}


int main()
{
    int opsi=1;
    int arr[100];
    int n;

    while(opsi != 4)
    {
        cout << "---MENU---" << endl;
        cout << "1. Input array \n";
        cout << "2. Urutkan element array \n";
        cout << "3. Cari element \n";
        cout << "4. Exit\n";
        cout << "Opsi yang ingin dipilih ? ";
        cin >> opsi;

        if(opsi == 1)
        {
        	cout << "Masukan panjang array : ";
            cin >> n;
            for(int i=0; i<n; i++)
            {
            	cout << "Masukan element ke-" << i + 1 << " : ";
                cin >> arr[i];
            }
            cout << endl;
        }
        else if(opsi == 2)
        {
        	if(n >= 2)
			{
            mergeSort(arr, n);
            cout << "Array sudah terurut : ";
            for (int i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl << endl;
			}
			else
			{
				cout << "Array masih kosong" << endl;
			}
        }
        else if(opsi == 3)
        {
        	if(n >= 1)
        	{
        	int cari;
			cout << "Angka yang ingin di cari? ";
			cin >> cari;
			int a = binarySearch(arr, n, cari);
            if (a != -1) {
                cout << "Angka ditemukan pada index: " << a << endl;
               } else {
                cout << "Angka tidak ditemukan." << endl;
            }
            cout << endl;
			}
			else
			{
				cout << "Array masih kosong" << endl;
			}
        }
        else if(opsi == 4)
        {
        	break;
		}
    }

    return 0;
}

