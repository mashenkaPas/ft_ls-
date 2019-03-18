#include <pwd.h>
#include <grp.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>

typedef struct		s_list
{	char			*name;
	struct	stat 	buf1;
	struct s_list	*next;
}					t_list;


int 	g_A = 0;
int 	g_L = 0;
int 	g_T = 0;
int 	g_R = 0;
int		g_ERROR = 0;

t_list 	*head = NULL;
t_list	*path = NULL;


int  checkerForFlags(char **argv){
	int i = 1;
	int j;
	int end = 0;
	while (argv[i])
	{
		j = 1;
		if (argv[i][0] == '-'  && end != 1)
		{
			while(argv[i][j])
			{
				if(argv[i][j] == 'a')
					g_A = 1;
				else if (argv[i][j] == 't')
					g_T= 1;
				else if (argv[i][j] == 'l')
					g_L = 1;
				else if (argv[i][j] == 'r')
					g_R = 1;
				else
					g_ERROR = 1;
				j++;
			}
		}
		if (argv[i][0] != '-')
			end = 1;
		if (end == 1)
			return i;
		i++;
	}
	printf("A:%d T:%d L:%d R:%d\n ", g_A, g_T, g_L, g_R);
	return i;
}

int ft_strlen(char *str);

char	*ft_strdup(char *s1)
{
	char	*d;
	int		i;

	i = 0;
	d = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (d == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		d[i] = s1[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

void insert(struct dirent *sd,struct stat buf)
{
	t_list *tmp = malloc(sizeof(t_list));
	tmp->name = ft_strdup(sd->d_name);

	memcpy(&(tmp->buf1),&buf,sizeof(buf));
	tmp->next = head;
	head = tmp;
}

void savepath (char *namepath)
{
	t_list *tmp = malloc(sizeof(t_list));
	tmp->name = namepath;
	tmp->next = path;
	path = tmp;
}


int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void swap_info(t_list *one, t_list *second)
{
	char *str_tmp;
	struct stat buf_tmp;

	str_tmp = one->name;
	buf_tmp = one->buf1;
	one->name = second->name;
	one->buf1 = second->buf1;
	second->name = str_tmp;
	second->buf1 = buf_tmp;
}

void sortLinkbyName()
{
	t_list *i;
	t_list *j;
	for(i = head;i->next != NULL; i = i->next)
	{
		for(j=i->next;j !=NULL; j = j->next)
		{
			int diff= ft_strcmp(i->name,j->name);
			if ((diff > 0  && g_R == 0) || (diff < 0 && g_R == 1))
				swap_info(i,j);
		}

	}
}

void sortpathbyName()
{
	t_list *i;
	t_list *j;
	for(i = path; i->next != NULL; i = i->next)
	{
		for(j=i->next;j !=NULL; j = j->next)
		{
			int diff= ft_strcmp(i->name,j->name);
			if (diff > 0)
				swap_info(i,j);
		}

	}
}

void sortLinkbyTime()
{
	t_list *i;
	t_list *j;
	int diff_m;
	int diff_n;

	for(i = head ;i->next != NULL; i = i->next )
	{
		for(j =i->next; j !=NULL; j = j->next)
		{
			diff_m = i->buf1.st_mtime - j->buf1.st_mtime;
			if ((diff_m < 0 && g_R == 0) || (diff_m > 0 && g_R == 1))
				swap_info(i,j);
			if (diff_m == 0)
			{
				diff_n = i->buf1.st_mtimespec.tv_nsec - j->buf1.st_mtimespec.tv_nsec;
				if ((diff_n < 0 && g_R == 0) || (diff_n > 0 && g_R == 1))
					swap_info(i,j);
			}

		}

	}
}

void	mode_print(int  mode)
{
	char c;
	size_t		i;
	static char temp[10];
	static char buff[] = "rwxrwxrwx";

	i = 0;
	while (i < 9)
	{
		temp[i] = (mode & (1 << (8 - i))) ? buff[i] : '-';
		i++;
	}
	temp[i] = '\0';
	if((mode & S_IFDIR) == S_IFDIR)
		c = 'd';
	else if ((mode & S_IFLNK) == S_IFLNK)
		c = 'l';
	else if ((mode & S_IFBLK) == S_IFBLK)
		c = 'b';
	else if ((mode & S_IFCHR) == S_IFCHR)
		c = 'c';
	else if ((mode & S_IFIFO) == S_IFIFO)
		c = 'p';
	else if ((mode & S_IFSOCK) == S_IFSOCK)
		c = 's';
	else
		c = '-';
	printf("%c%s ", c, temp);
}

int total_function()
{
	int total = 0;
	t_list *begin;
	begin = head;
	if (g_A == 1)
	{
		while(begin)
		{
			total += begin->buf1.st_blocks;
			begin = begin->next;
		}
	}
	else if (g_A == 0)
	{
		while (begin)
		{
			if (begin->name[0] != '.')
				total += begin->buf1.st_blocks;
			begin = begin->next;
		 }

	}
	return (total);
}
void flagL()
{
	t_list *begin;
	begin = head;
	printf("%s %d\n","total :",total_function());
	while (begin != NULL)
	{
		if (g_L == 1)
		{
			if((begin->name[0] != '.') || (g_A == 1 && begin->name[0] == '.'))
			{
				mode_print(begin->buf1.st_mode);
				printf("%hu ",begin->buf1.st_nlink);
				printf("%-5s ",getpwuid(begin->buf1.st_uid)->pw_name);
				printf("%s ",getgrgid(begin ->buf1.st_gid)->gr_name);
				printf("%6lld ",begin->buf1.st_size);
				printf("%.12s ",4+(ctime (&begin->buf1.st_mtime)));
				printf("%s\n ",begin->name);

			}
		}
		begin = begin->next;
	}
}

void printHelper()
{
	t_list *begin;

	begin = head;
	sortLinkbyName();
	if (g_L == 1)
		flagL();
	else if (g_L == 0)
	{
		if (g_A == 1)
		{
			while (begin != NULL)
			{
				printf("%s\n",begin->name);
				begin = begin->next;
			}
		}
		if (g_A == 0 )
		{
			while (begin != NULL)
			{
				if (begin->name[0] != '.')
					printf("%s\n",begin->name);
				begin = begin->next;
			}
		}
	}
}

void printList ()
{
	t_list *begin = head;
	if (g_T == 1)
	{
		sortLinkbyTime();
		if (g_L == 1)
			flagL();
		else if (g_L == 0)
		{
			if (g_A == 1 )
			{
				while (begin != NULL)
				{
					printf("%s\n",begin->name);
					begin = begin->next;
				}
			}
			if (g_A == 0)
			{
				while (begin != NULL)
				{
					if (begin->name[0] != '.')
						printf("%s\n",begin->name);
					begin = begin->next;
				}
			}
		}
	}
	else
		printHelper();
}

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return (i);
}

char *getpath(char *dirpath, char *str)
{
	int i = 0;
	int j = 0;
	int size;
	char *word;
	size = ft_strlen(dirpath) + ft_strlen(str) + 2;
	word = (char*)malloc(sizeof(char) * size);
	while(dirpath[i])
	{
		word[i] = dirpath[i];
		i++;
	}
	word[i] = '/';
	i++;
	j = 0;
	while(str[j])
	{
		word[i] = str[j];
		i++;
		j++;
	}
	word[i] = '\0';
	return word;
}

void checkDir(int i, char **argv)
{
	char *dirpath;
	if (argv[i] == NULL)
		savepath(".");
	else
	{
		dirpath = argv[i];
		savepath(dirpath);
	}
}

int size_path()
{
	int size = 0;
	t_list *current = path;
	while(current)
	{
		size++;
		current = current->next;
	}
	return size;
}

void dir_helper()
{
	DIR *dir;
	struct stat buf;
	struct dirent *sd;
	sortpathbyName();
	t_list *current = path;
	while(current != NULL)
	{
		head = NULL;
		if(size_path() != 1)
			printf("%s%c\n",current->name, ':');
		dir = opendir(current->name);
		if (dir == NULL)
		{
			printf("b_ls: %s%s",current->name," :No such file or directory");
		}
		else
		{
			while ((sd = readdir(dir)))
			{
				lstat(getpath(current->name,sd->d_name), &buf);
				insert(sd,buf);
			}
			printList();
			printf("\n");
			closedir(dir);
		}
		current = current->next;
	}
}

int main (int argc , char **argv)
{
	int i;
	i = 0;
	if(argc)
		i = checkerForFlags(argv);
	if (g_ERROR == 1)
	{
		printf("illegal option --");
		return (0);
	}
	if(argv[i] == NULL)
		checkDir(i, argv);
	while(argv[i] != NULL)
	{

		checkDir(i, argv);
		i++;
	}

		dir_helper();
	return(0);
}
