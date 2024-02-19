#include <stdio.h>
#include <stdlib.h>

int partition(int*v, int low, int high)
{
    int pivot = v[high];
    int sm = low-1;

    for(int i = low; i< high;i++ )
    {
        if(v[i] <= pivot)
        {
            sm = sm+1;
            int aux= v[i];
            v[i] = v[sm];
            v[sm] =aux;
       }
    }
    int aux= v[high];
    v[high] = v[sm+1];
    v[sm+1]= aux;
    return sm+1;
}

void quicksort(int*v, int low, int high)
{
    if(low >= high) return;

    int poz = partition(v, low, high); //fct partition arata pozitia pe care trebuie pusa pivotul in sir
    quicksort(v, low, poz-1);
    quicksort(v, poz+1, high);
}

int main()
{
    int n;
    scanf("%d", &n);

    int *v = (int*)calloc(n, sizeof(int));
    for(int i=0; i<n; i++)
    {
        scanf("%d", &v[i]);
    }

    quicksort(v, 0, n-1);

    for(int i= 0 ; i<n ; i++)
    {
        printf("%d ", v[i]);
    }
    return 0;
}
