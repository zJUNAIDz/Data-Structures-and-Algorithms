#include <stdio.h>
int i, j, n, a[100], val, ch;
void create();
void delete_element();
void display();
void search();
void sort();
void reverse();
int main()
{
  if (ch > 0)
  {
    printf("\n MENU \n1.create \n2.remove\n3.display\n4.search\n5.sort\n6.reverse\n7.exit");
    printf("\n Enter for choice: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      create();
      break;
    case 2:
      delete_element();
      break;
    case 3:
      display();
      break;
    case 4:
      search();
      break;
    case 5:
      sort();
      break;
    case 6:
      reverse();
      break;
    case 7:
      return 0;
      break;
    default:
      printf("Invalid choice");
      break;
    }
  }
  return 0;
}
void create()
{
  printf("\nEnter the size of array: ");
  scanf("%d", &n);
  printf("\n Enter the elements: ");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  printf("\nArray created successfully.");
}
void delete_element()
{
  int pos;
  printf("\n Enter the element position to remove:");
  scanf("%d", &pos);
  for (i = pos - 1; i < n - 1; i++)
  {
    a[i] = a[i + 1];
  }
  n--;
  display();
}
void display()
{
  for (i = 0; i < n; i++)
  {
    printf("%d\t", a[i]);
  }
}
void search()
{
  int val;
  printf("\n Enter element to search for: ");
  scanf("%d", &val);
  for (i = 1; i < n + 1; i++)
  {
    if (a[i] == val)
    {
      printf("\nElement found at position is %d", i + 1);
      break;
    }
  }
  if (i == n)
  {
    printf("\n Element not found in array.");
  }
}
void sort()
{
  int temp;
  for (i = 0; i < n; i++)
  {
    for (j = i + 1; j < n; j++)
    {
      if (a[j] < a[i])
      {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }
  }
  display();
}
void reverse()
{
  int temp;
  j = n - 1;
  for (i = 0; i < n / 2; i++)
  {
    temp = a[i];
    a[i] = a[j];
    a[j] = temp;

    j--;
  }
}