#include <stdio.h>
#include <mpi.h>
#include <limits.h>

/* a little diddy to display what hints are supported by a given MPI-IO implementation */

#define CHECK(fn) {int errcode; errcode = (fn); if (errcode != MPI_SUCCESS) handle_error(errcode, NULL); }

static void handle_error(int errcode, char *str)
{       
        char msg[MPI_MAX_ERROR_STRING];
        int resultlen;
        MPI_Error_string(errcode, msg, &resultlen);
        fprintf(stderr, "%s: %s\n", str, msg);
        MPI_Abort(MPI_COMM_WORLD, 1);
}


static void dump_keys(MPI_Info info) {
    int i, nkeys, flag;
    char key[MPI_MAX_INFO_KEY];
    char value[MPI_MAX_INFO_VAL];

    MPI_Info_get_nkeys(info, &nkeys);

    for (i=0; i<nkeys; i++) {
        MPI_Info_get_nthkey(info, i, key);
        MPI_Info_get(info, key, MPI_MAX_INFO_VAL-1, value, &flag);
        printf("key = %-25s  value = %-10s\n", key, value);
    }
    MPI_Info_get(info, "bg_nodes_pset", MPI_MAX_INFO_VAL-1, value, &flag);
    if (flag) printf("key = %-25s  value = %-10s\n", "bg_nodes_pset", value);
    return;
}

int main (int argc, char ** argv)
{
	MPI_File fh;
	MPI_Info info_used;
	int rank;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);

	CHECK(MPI_File_open(MPI_COMM_WORLD, argv[1],
		    MPI_MODE_RDWR|MPI_MODE_CREATE,
		    MPI_INFO_NULL, &fh));

	CHECK(MPI_File_get_info(fh, &info_used));
	if (rank == 0) dump_keys(info_used);

	CHECK(MPI_Info_free(&info_used));

	CHECK(MPI_File_close(&fh));
	MPI_Finalize();
	return 0;
}
