#include "myinclude.h"

void read(int A[], int n)
{
        int i;
        for (i = 0; i < n; i++)
                scanf("%d", &A[i]);
}

void print(int A[], int n)
{
        int i;
        for (i = 0; i < n; i++)
                printf("%d ", A[i]);
        printf("\n");
}

int max(int A[], int n)
{     
        int h_ih = A[0];
        for(int i = 0; i < n; i++){
                if(A[i] > h_ih)
                        h_ih = A[i];
        }
        return h_ih;
}

int min(int A[], int n)
{
       int baga = A[0];
        for(int i = 0; i < n; i++){
                if(A[i] < baga)
                        baga = A[i];
        }
        return baga;
}

void copy(int A[], int n, int B[])
{
        for(int i = 0; i < n; i++){
                B[i] = A[i];
        }
}

int find(int A[], int n, int x)
{
       for(int i = 0; i < n; i++){
                if(A[i] == x){
                        return i;
                }
       }
       return -1;
}
int make_set(int A[], int n, int B[]) {
    int t = 0;
    for(int i = 0; i < n; i++) {
        int gants = 1;
        for(int j = 0; j < i; j++) {
            if(A[i] == B[j]) {//A husnegt dehi element B dotor bgaa esehiig shalgaad
                gants = 0;      //baival ene for loopees garch daraagiin elementiig shalgaad yavna
                break;
            }
        }
        if(gants == 1){ //gants gsn huvisagch oorchlogdoogui bol B husnegted A[i] utgiig olgono
            B[t] = A[i];
            t++;
        }
    }
    return t; 
}
int union_set(int A[], int n, int B[], int m)
{
        int k, s = n;
        for(int i = 0; i < m; i++){
                k = 0;
                for(int j = 0; j < s; j++){
                        if(B[i] == A[j]){ //B -d bgaa bolowch A husnegted bhgu elementiig A husnegted zalgah tul 
                                k = 1;          // bgaa ugui esehiig shalgaj bna gsn ug bolno
                                break;
                        }
                }
                if(k == 0){
                        A[s] = B[i];
                        s++; //s ni shine husnegtiin hemjeeg hadgalj bgaa
                }                       
        }
       return s;
}
int intersection_set(int A[], int n, int B[], int m, int C[])
{
        int t = 0, x = 0;
        for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                        if(A[i] == B[j]){ //A ba B hoyrt zereg bgaa elementiig awah tul ingej shalgana
                                t = 0;  //for loopee x buyu C -d omno orson bgaa elementiin toogoor guilgesen
                                for(int k = 0; k < x; k++){ //daraa ni tuhain element omno ni C husnegted hadgalagdsan bish uu 
                                        if(C[k] == A[i]){       //gdgiig shalgaad bhgu bol C husnegted hadgalna
                                                t = 1;
                                                break;
                                        }
                                }
                                if(t == 0){
                                        C[x] = A[i];
                                        x++; //C husnegtiin hemjeeg ilerhiilne
                                }
                        }
                }
        }
        return x;  
}
