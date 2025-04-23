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
for (int i = 0; i < num_frames; i++) {
frames[i] = -1;
}
int oldest_frame = 0;
for (int i = 0; i < num_pages; i++) {
int page = pages[i];
int page_found = 0;
for (int j = 0; j < num_frames; j++) {
if (frames[j] == page) {
page_found = 1;
break;
}
}
if (!page_found) {
frames[oldest_frame] = page;
oldest_frame = (oldest_frame + 1) % num_frames;
page_faults++;
}
}
printf("Total page faults using FIFO algorithm: %d\n", page_faults);
return 0;
}