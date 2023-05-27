/*
** EPITECH PROJECT, 2022
** my_strncmp.c
** File description:
** Reproduce the behavior of the strncmp function.
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    for (; s1[i] == s2[i] && i != n && s1[i] && s2[i]; i++) {
        continue;
    }
    if ((s1[i] == '\0' && s2[i] == '\0') || i == n) {
        return 0;
    }
    if (s1[i] > s2[i]) {
        return 1;
    }
    if (s1[i] < s2[i]) {
        return -1;
    }
    return 0;
}
