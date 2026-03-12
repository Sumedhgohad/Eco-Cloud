#include <stdio.h>
#include "PCB.h"
#include "PriorityQueue.h"
#include "JobTrie.h"

int main() {
    printf("\n==================================================\n");
    printf("   ECO-CLOUD: DATA STRUCTURE TERMINAL TEST\n");
    printf("==================================================\n\n");

    PCB* p1 = create_pcb("joba", 10, 256);
    PCB* p2 = create_pcb("jobb", 5, 128);
    PCB* p3 = create_pcb("jobc", 20, 512);

    printf(">>> TESTING PRIORITY QUEUE <<<\n");
    PriorityQueue* pq = create_priority_queue();
    
    enqueue(pq, p1, 3);
    enqueue(pq, p2, 1);
    enqueue(pq, p3, 2);
    
    while (!is_empty(pq)) {
        PCB* job = dequeue(pq);
        printf("   Priority Dequeue: ");
        print_pcb_details(job);
    }

    printf("\n>>> TESTING JOB TRIE <<<\n");
    Trie* jobDatabase = create_trie();
    insert_job(jobDatabase, "joba", p1);
    insert_job(jobDatabase, "jobb", p2);
    insert_job(jobDatabase, "jobc", p3);

    printf("Searching for 'jobb': FOUND! -> ");
    PCB* search1 = search_job(jobDatabase, "jobb");
    if (search1) print_pcb_details(search1);

    printf("Searching for 'jobx': ");
    PCB* search2 = search_job(jobDatabase, "jobx");
    if (!search2) printf("Not Found.\n");

    destroy_priority_queue(pq);
    destroy_trie(jobDatabase);
    destroy_pcb(p1);
    destroy_pcb(p2);
    destroy_pcb(p3);

    printf("\n==================================================\n");
    printf("               ALL TESTS COMPLETED                \n");
    printf("==================================================\n\n");

    return 0;
}
