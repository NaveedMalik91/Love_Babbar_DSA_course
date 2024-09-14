void printDuplicates(int arr[], int n)
// {
//     unordered_map<int, int> freq;
//     vector<int> duplicates;
//     // Count the frequency of each element
//     for (int i = 0; i < n; i++)
//     {

//         freq[arr[i]]++;
//     }
//     bool flag = false; // added a flag to check if there are no duplicate elements
//     for (int i = 0; i < n; i++)
//     {
//         if (freq[arr[i]] > 1)
//         {
//             flag = true;
//         }
//         else if (freq[i] == 1)
//         {
//             cout << arr[i] << " ";
//         }
//     }

//     if (!flag)
//     {
//         cout << "No duplicate elements";
//     }
// }