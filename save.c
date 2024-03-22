int ft_strldd(char **str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}
int	get_first_word(char *str)
{
	int i;

	char *strs = ft_strtrim(str," ");
	i = 0;
	while ((strs[i] != 9  && strs[i] != 32) && strs[i])
		i++;
	return(i);
}
char	**get_files (char **str)
{
	int len;
	char **strs ;
	char *word ;
	int fw_len;
	len = ft_strldd(str);
	fw_len = get_first_word(str[1]);
	strs =  malloc(sizeof(char *) * (len + 1));
	word = malloc(sizeof(char) * (fw_len + 1));
 	printf("%d",fw_len);
	return (0x0);
}


