/*
** EPITECH PROJECT, 2021
** my_revstr
** File description:
** task 03
*/

int my_strlen(char const *str);

char my_swapchar(char *point1, char *point2)
{
    char letter;

    letter = *point1;
    *point1 = *point2;
    *point2 = letter;
    return (0);
}

char *my_revstr(char *str)
{
    int i = my_strlen (str);
    int j = i / 2;

    for (int k = 0; k < j; k++) {
        my_swapchar (&str[k], &str[i - 1 - k]);
    }
    return (str);
}
