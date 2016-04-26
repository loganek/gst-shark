#include <stdlib.h>
#include <string.h>
#include "gstparser.h"
#include "gstctf.h"
#include "gstsharkclient.h"

#define TCP_CONN

static const char cpuusage_metadata_event[] = "event {\n\
	name = cpuusage;\n\
	id = %d;\n\
	stream_id = %d;\n\
	fields := struct {\n\
		integer { size = 32; align = 8; signed = 0; encoding = none; base = 10; } _cpunum;\n\
		integer { size = 64; align = 8; signed = 0; encoding = none; base = 10; } _cpuload;\n\
	};\n\
};\n\
\n";

void tcp_conn_write(void);

int main (int argc, char * argv[])
{
    gchar *metadata_event;
    
    gst_ctf_init ();
    
    
    metadata_event =
    g_strdup_printf (cpuusage_metadata_event, CPUUSAGE_EVENT_ID, 0);
    add_metadata_event_struct (metadata_event);
    g_free (metadata_event);

#ifdef TCP_CONN
    //~ tcp_conn_write();
#endif
    /* Events */
    //~ do_print_cpuusage_event (CPUUSAGE_EVENT_ID, 0, 75);

    gst_ctf_close ();

    return EXIT_SUCCESS;
}
