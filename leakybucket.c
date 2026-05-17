#include<stdio.h>
int main() {
    int incoming, outgoing, bucket_size, n, store = 0;
    printf("Enter bucket size, outgoing rate and no of inputs: ");
    scanf("%d %d %d", &bucket_size, &outgoing, &n);
    while(n > 0) {
        printf("Enter incoming packet size: ");
        scanf("%d", &incoming);
        printf("Incoming packet size: %d\n", incoming);
        if(incoming <= (bucket_size - store)) {
            store += incoming;
        } else {
            printf("Dropped packets: %d\n", incoming - (bucket_size - store));
            store = bucket_size;
        }
        printf("Bucket: %d/%d\n", store, bucket_size);
        if(store >= outgoing)
            store -= outgoing;
        else
            store = 0;
        printf("After outgoing: %d packets left\n\n", store);
        n--;
    }
    return 0;
}
########################################################################################
#include<stdio.h>
int main(){
    int in, out, bs, n, store = 0;
    printf("Enter bucket size, outgoing rate and no of inputs: ");
    scanf("%d%d%d", &bs, &out, &n);
    while(n--){
        printf("Enter incoming packet size: ");
        scanf("%d", &in);
        printf("Incoming packet size: %d\n", in);
        if(in <= bs - store)
            store += in;
        else
        {
            printf("Dropped packets: %d\n",in - (bs - store));
            store = bs;
        }
        printf("Bucket: %d/%d\n", store, bs);
        if(store >= out)
            store -= out;
        else
            store = 0;
        printf("After outgoing: %d packets left\n\n", store);
    }
    return 0;
}
