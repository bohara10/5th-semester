#include <stdio.h>
int main() {
int num_pages, num_frames, page_faults = 0;
printf("Enter the number of pages: ");
scanf("%d", &num_pages);
int pages[num_pages];

printf("Enter the page reference string: ");
for (int i = 0; i < num_pages; i++) {
scanf("%d", &pages[i]);
}
printf("Enter the number of frames: ");
scanf("%d", &num_frames);
int frames[num_frames];
int last_used[num_frames];
for (int i = 0; i < num_frames; i++) {
frames[i] = -1;
last_used[i] = -1;
}
for (int i = 0; i < num_pages; i++) {
int page = pages[i];
int page_found = 0;
for (int j = 0; j < num_frames; j++) {
if (frames[j] == page) {
page_found = 1;
last_used[j] = i;
break;
}
}
if (!page_found) {
int lru_frame = 0;
for (int j = 0; j < num_frames; j++) {
if (last_used[j] < last_used[lru_frame]) {
lru_frame = j;
}
}
frames[lru_frame] = page;
last_used[lru_frame] = i;
page_faults++;
}
}
printf("Total page faults using LRU algorithm: %d\n", page_faults);
return 0;
}