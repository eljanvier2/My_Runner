/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** task 06
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] == s2[i])
            i++;
        else if (s1[i] > s2[i])
            return (1);
        else
            return (-1);
    }
    if (s1[i] == '\0' && s2[i] != '\0')
        return (-1);
    else if (s2[i] == '0' && s1[i] != '\0')
        return (1);
    else
        return 0;
}
