#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include<string.h>

/* Modify these two lines according to the project */
#include <bus_reservation.h>
#define PROJECT_NAME    "bus_reservation"

/* Prototypes for all the test functions */
void test_bus(void);
void test_book(void);
void test_read_number(void);
void test_read_name(void);
void test_status(void);
void test_status_1(void);
void test_cancel(void);

/* Start of the application test */
int main() {
/* Note: Do not edit START*/
  /*Initialize and setup the Test Framework */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();
  CU_pSuite suite = CU_add_suite(PROJECT_NAME, 0, 0);
/* Note: Do not edit END */


  /* Add your test functions in this format for testing*/
  CU_add_test(suite,"bus",test_bus);
  CU_add_test(suite,"book",test_book);
  CU_add_test(suite,"read_number",test_read_number);
  CU_add_test(suite,"read_name",test_read_name);
  CU_add_test(suite,"status",test_status);
  CU_add_test(suite,"status_1",test_status_1);
  CU_add_test(suite,"cancel",test_cancel);

/* Note: Do not edit START*/
  /* Setup Test Framework to output the result to Screen */
  CU_basic_set_mode(CU_BRM_VERBOSE);

  /* run the unit test framework*/
  CU_basic_run_tests();

  /* Cleaning the Resources used by Unit test framework */
  CU_cleanup_registry();
/* Note: Do not edit END */
  return 0;
}

/* Write all the test functions */
void test_bus(void)
{
    CU_ASSERT(1==bus(1));
}

void test_book(void)
{
    char name[100]="Dhyan";
    char busnum[10]="1";
    CU_ASSERT(1==book(busnum,1,name));

}
void test_status(void)
{
  CU_ASSERT(1==status(1));

}
void test_cancel(void)
{
  CU_ASSERT(1==cancel(1));

}

void test_read_number(void)
{
  CU_ASSERT(1==read_number(1));

}
void test_read_name(void)
{
  CU_ASSERT(1==read_name(1));
}
void test_status_1(void)
{
  CU_ASSERT(1==status_1(1));

}


