//
// Created by genta on 2024/06/07.
//

#include "sd.h"
#include "stdarg.h"

extern char SDPath[4];

                                        /* FatFs function common result code */
FATFS sd_fat_fs_;  /* File system object for SD card logical drive */
FIL my_file_;     /* File object */
char *sd_path_ = SDPath; /* SD card logical drive path */

uint8_t wtext[] = "BOOTED"; /* File write buffer */
uint8_t rtext[_MAX_SS];
char init_file_name[] = "BOOTLOG.TXT\0";
int written_line = 0;


int init_sd(){
    FRESULT f_res;
    for(int i = 0; i < 5; i++)
	{
		f_res = f_mount(&sd_fat_fs_,  (TCHAR const*)sd_path_, 0);
		if(f_res == FR_OK || f_res == FR_EXIST)
		{
			break;
		}
	}
    for(int i = 0; i < 5; i++)
    {
        f_res = f_open(&my_file_, "LOG.TXT", FA_OPEN_ALWAYS |  FA_WRITE);
        if(f_res == FR_OK || f_res == FR_EXIST)
        {
            break;
        }
    }
    f_lseek(&my_file_, f_size(&my_file_));

    for(int i = 0; i < 5; i++){
        UINT byteswritten;
        f_res = f_write(&my_file_, wtext, sizeof(wtext), &byteswritten);
        if((byteswritten != 0) && (f_res == FR_OK))
        {
            HAL_Delay(50);
            break;
        }
        HAL_Delay(50);
        printf("cannot write");
    }
    return 0;
}


int write_line(const uint8_t *text, size_t size){
	FRESULT f_res;
    size_t byteswritten = 0;
    if(written_line > 10){
    	f_res=f_close(&my_file_);
		for(int i = 0; i < 5; i++)
		{
			f_res = f_open(&my_file_, "LOG.TXT", FA_OPEN_ALWAYS |  FA_WRITE);
			if(f_res == FR_OK || f_res == FR_EXIST)
			{
				break;
			}
		}
		f_lseek(&my_file_, f_size(&my_file_));
    	f_res = f_write(&my_file_, text, size, &byteswritten);
    	written_line = 0;
    	return byteswritten;
    }
    f_res = f_write(&my_file_, text, size, &byteswritten);
    written_line++;
	return byteswritten;
}

