/*
** EPITECH PROJECT, 2022
** my_strlen.c
** File description:
** Counts and returns the number of characters
** found in the string passed as parameter.
*/

int my_strlen(char const *str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        count++;
    }
    return count;
}
