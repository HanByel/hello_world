#include <pthread.h>
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>

void *pthread_fuction(void *data)
{
    int *local_data=0;
    local_data = (int*)data;
    while(1){
        *local_data+=1;
        sleep(1);
    }
}

main()
{
    pthread_t p_thread[3];
    int thr_id;
    int values[3]={0,};
    int *p[3];//={0,};

    for(int i=0;i<3;i++)    p[i]=&values[i];

    thr_id = pthread_create(&p_thread[0], NULL, pthread_fuction, (void *)p[0]);
    thr_id = pthread_create(&p_thread[1], NULL, pthread_fuction, (void *)p[1]);
    thr_id = pthread_create(&p_thread[3], NULL, pthread_fuction, (void *)p[2]);

    while(1){
        printf("p1 : %d, p2 : %d, p3 : %d\n", *p[0], *p[1], *p[2]);
        sleep(1);
    }
}
