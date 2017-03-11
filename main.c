#include <stdio.h>
#include <time.h>
#include <sys/times.h>
#include <unistd.h>
#include <inttypes.h>
#include <dlfcn.h>
#include "list.h"

clock_t start_real;
clock_t prev_real;
clock_t now_real;
struct tms start;
struct tms prev;
struct tms now;

void check()
{
  prev_real = now_real;
  //prev.tms_utime = now.tms_utime;
  //prev.tms_stime = now.tms_stime;
  prev.tms_utime = now_real;
  prev.tms_stime = now_real;

  //now_real = times(&now);
  now_real = clock();

  printf("---------------------\n");
  printf("Od poczatku dzialania:\n");
  printf("  Real: %g\n", (double)(now_real - start_real)/CLOCKS_PER_SEC);
  printf("  User: %g\n", (double)(now.tms_utime - start.tms_utime)/CLOCKS_PER_SEC);
  printf("  Sys: %g\n", (double)(now.tms_stime - start.tms_utime)/CLOCKS_PER_SEC);
  printf("Od poprzedniego checkpointu:\n");
  printf("  Real: %g\n", (double)(now_real - prev_real)/CLOCKS_PER_SEC);
  printf("  User: %g\n", (double)(now.tms_utime - prev.tms_utime)/CLOCKS_PER_SEC);
  printf("  Sys: %g\n", (double)(now.tms_stime - prev.tms_utime)/CLOCKS_PER_SEC);
}

void mysleep(){
  int i=0;
  for(i=0; i<100000000; i++){
    i++; i--; i++; i--;
  }
}

int main()
{
  #ifdef DLL
    void *handle = dlopen("./libmylist.so", RTLD_LAZY);
    void (*List_add_element)(List*, info) = dlsym(handle, "List_add_element");
    void (*List_add)(List * , const char*, const char* , const char*, long, const char*)= dlsym(handle,"List_add");
    ListNode* (*List_find)(List*, const char*) = dlsym(handle, "List_find");
    List* (*List_create)(void) = dlsym(handle, "List_create");
    void (*List_remove)(List*, ListNode*) = dlsym(handle, "List_remove");
    List* (*List_sort)(List*);
  #endif

}

List *mylist = List_create();
mylist->first=NULL;
mylist->last=NULL;

  //start_real = times(&start);
  start_real = clock();
  now_real = start_real;
  //now.tms_utime = start.tms_utime;
  //now.tms_stime = start.tms_stime;
  now.tms_utime = start_real;
  now.tms_stime = start_real;
  printf("\nCZAS START!\n");
  /*#########################
  ## DODAWANIE 7 KONTAKTÓW ##
  #########################*/
  checkpoint();
  printf("\nDODAWANIE KONTAKTÓW\n");
const char * imie1 = "Jacek";
const char * imie2 = "Mateusz";
const char * imie3 = "Pawel";
const char * imie4 = "Adam";
const char * imie5 = "Maciek";
const char *nazwisko = "Nabywaniec";
const char *nazwisko1 = "Nabywaniec";
const char * nazwisko2="Kowalski";
const char * nazwisko3="Dąbrowski";
const char * nazwisko4="Wesoły";
const char * nazwisko5="Jaworski";
const char *adres = "Kraków";
const char data = "24-07-96";
long telefon = 789412093;
List_add(mylist,imie1,nazwisko, data, telefon, adres);
List_add(mylist,imie2,nazwisko, data, telefon, adres);
List_add(mylist,imie3,nazwisko, data, telefon, adres);
List_add(mylist,imie4,nazwisko, data, telefon, adres);
List_add(mylist,imie5,nazwisko, data, telefon, adres);
  checkpoint();

  printf("\nBREAK\n");
  mysleep();
  checkpoint();
  /*####################
  ## SORTOWANIE LISTY ##
  ####################*/
  printf("\nSORTOWANIE KONTAKTÓW\n");
  mylist=List_sort(mylist);
  checkpoint();

  printf("\nBREAK\n");
  mysleep();
  checkpoint();
  /*#########################
  ## WYSZUKIWANIE ELEMENTU ##
  #########################*/
  printf("\nSZUKANIE KONTAKTU\n");
  ListNode * a =List_find(mylist,"Kowalski");
  checkpoint();

  printf("\nBREAK\n");
  mysleep();
  checkpoint();
  /*###########################
  ## USUWANIE ELEMENTU LISTY ##
  ###########################*/
  printf("\nUSUWANIE KONTAKTU\n");
  List_remove(mylist, mylist->first->next->next);
  checkpoint();

  #ifdef DLL
    dlclose(handle);
  #endif
return 0;
