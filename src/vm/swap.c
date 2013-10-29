#include "swap.h"

void swap_init ()
{
	unsigned size;
	swap_disk = disk_get (1,1);
	size = disk_size (swap_disk);
	frame_alloc = bitmap_create (size / PG_SIZE);
	lock_init (&swap_lock);
}

void swap_in (uint8_t *upage, uint8_t *kpage)
{
	lock_acquire (&swap_lock);

	int i;
	uint8_t dst, *src;
	
	dst = (disk_sector_t) bitmap_scan_and_flip (frame_alloc, 0, 1, false);
	if (dst == BITMAP_ERROR)
		PANIC();

	for (i=0; i<8; i++)
		disk_write (swap_disk, dst*8 + i, src);
	bitmap_set (frame_alloc, dst, true);

	/* Empty frame */

	lock_release (&swap_lock);
}

void swap_out (uint8_t *upage, uint8_t *kpage)
{
	lock_acquire (&swap_lock);
	
	disk_sector_t src;
	uint8_t *dst;

	/* Find swap slot containing upage */
	src = asdf;

	/* Find swap 

	disk_read (swap_disk, dst, src);

	bitmap_set (frame_alloc, src, false);
}
