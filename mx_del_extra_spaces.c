#include "libmx.h"

static int mx_length_without_spaces(char *str) {
    int length = 0;

    for (int i = 0; i < mx_strlen(str) - 1; i++) {
        if (mx_isspace(str[i]) && mx_isspace(str[i + 1])) {
            length++;
        }
    }
    return mx_strlen(str) - length;
}

char *mx_del_extra_spaces(const char *str) {
    if (!str) return NULL;
    char *trim_str = mx_strtrim(str);
    if (!trim_str) return (char *)str;

    int result_length = mx_length_without_spaces(trim_str);
    char *result = mx_strnew(result_length);
    if (!result) return NULL;

    int counter = 0;
    for (int i = 0; i < mx_strlen(trim_str); i++) {
        if (!mx_isspace(trim_str[i])) {
            result[counter] = trim_str[i];
            counter++;
        }
        else if (!mx_isspace(trim_str[i + 1])) {
            result[counter] = ' ';
            counter++;
        }
    }
    mx_strdel(&trim_str);
    return result;
}

// int main() {
//   char name[] = "\f My   name...  \nis \r Neo   \t\n ";
//   char *res = mx_del_extra_spaces(name);
//   printf("%s\n", res);
//   mx_strdel(&res);
//   system("leaks -q libmx");
//   return 0;
// }
