if (!strcmp(cmd_token[0], "cd"))
execl("/bin/sh", "-c", cmd_token[0],..., (const char *)0);
