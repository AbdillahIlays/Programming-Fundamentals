//Abdullah Ilyas
//25L-0826

#include <iostream>
using namespace std;

const int mr = 50;
const int mc = 50;
const int ml = 20;
const int mcell = mr * mc;

bool eq(const char a[], const char b[]) 
{
   int i = 0;
   while (a[i] != '\0' && b[i] != '\0') 
   {
       if (a[i] != b[i]) return false;
       i++;
   }
   return (a[i] == '\0' && b[i] == '\0');
}

void cp(char dest[], const char src[]) 
{
   int i = 0;
   while (src[i] != '\0') {
       dest[i] = src[i];
       i++;
   }
   dest[i] = '\0';
}

bool isEmpty(const char s[]) 
{
   return (s[0] == '-' && s[1] == '-' && s[2] == '\0');
}

int main() 
{
   int R, C;
   cout << "Enter number of rows and columns: ";
   cin >> R >> C;
   if (R < 1 || C < 1 || R > mr || C > mc) return 0;

   char cell[mcell][ml];

   for (int i = 0; i < R; i++) {
       for (int j = 0; j < C; j++) {
           cout << "Enter index [" << i << "][" << j << "]: ";
           int idx = i * C + j;
           cin >> cell[idx];
       }
   }

   int emptyCount = 0;
   char c[1000][ml];
   int freq[1000];
   int courseCount = 0;

   for (int i = 0; i < R; i++) {
       for (int j = 0; j < C; j++) {
           int idx = i * C + j;
           if (isEmpty(cell[idx])) 
           {
               emptyCount++;
               continue;
           }
           int pos = -1;
           for (int k = 0; k < courseCount; k++) 
           {
               if (eq(c[k], cell[idx])) {
                   pos = k; break;
               }
           }
           if (pos == -1) 
           {
               cp(c[courseCount], cell[idx]);
               freq[courseCount] = 1;
               courseCount++;
           }
           else freq[pos]++;
       }
   }

   for (int i = 0; i < R; i++) {
       char reported[50][ml];
       int reportedCount = 0;
       for (int j = 0; j < C; j++) {
           int idx1 = i * C + j;
           if (isEmpty(cell[idx1])) continue;
           bool already = false;
           for (int t = 0; t < reportedCount; t++) {
               if (eq(reported[t], cell[idx1])) { already = true; break; }
           }
           if (already) continue;
           bool foundDup = false;
           for (int k = j + 1; k < C; k++) {
               int idx2 = i * C + k;
               if (!isEmpty(cell[idx2]) && eq(cell[idx1], cell[idx2])) {
                   foundDup = true; break;
               }
           }
           if (foundDup) {
               cout << "Conflict : " << cell[idx1]
                   << " appears twice in Slot " << (i + 1) << endl;
               cp(reported[reportedCount], cell[idx1]);
               reportedCount++;
           }
       }
   }

   for (int j = 0; j < C; j++) {
       for (int i = 0; i + 1 < R; i++) {
           int idxA = i * C + j;
           int idxB = (i + 1) * C + j;
           if (!isEmpty(cell[idxA]) && eq(cell[idxA], cell[idxB])) {
               cout << "Conflict : " << cell[idxA]
                   << " appears consecutively in Room " << (j + 1) << endl;
           }
       }
   }

   int maxFreq = 0;
   char mostCourse[ml];
   mostCourse[0] = '\0';
   for (int i = 0; i < courseCount; i++) {
       if (freq[i] > maxFreq) {
           maxFreq = freq[i];
           cp(mostCourse, c[i]);
       }
   }

   cout << "Total Empty Slots : " << emptyCount << endl;
   if (maxFreq > 0) {
       cout << "Most Frequent Course : " << mostCourse << endl;
   }
   else {
       cout << "Most Frequent Course : None" << endl;
   }

   system("pause");

   return 0;
}
    