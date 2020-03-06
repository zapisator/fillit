/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 15:05:36 by ftothmur          #+#    #+#             */
/*   Updated: 2019/07/18 15:44:41 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
** Header files dependencies.
**
** string.h for NULL and size_t.
** stdlib.h for malloc and free.
** unistd.h for write.
*/
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

/*
** MAX_SIZE is a MACRO SIZE_MAX of stdint.h, which is forbidden to include
** at the project. It's size is size_t or 18446744073709551615LUU == 2 ^ 64 - 1
** It is too big, to count. Malloc returns error for this value, zsh kills
** proces, when it is bigger then MAX_INT * 2048. But it do well with
** MAX_INT * 2, which is 4294967295. So let MAX_SIZE be it. Or, if necessary,
** you can use a value equal to the massed address. This is the number that can
** be obtained using 8 bytes. size_t(-1)
** macro STDOUT is for fd of ft_putchar etc.
** macro MIN_INT is for mininimal integer value
*/

# ifndef SIZE_MAX
#  define SIZE_MAX		0xffffffffffffffffL
# endif

# define MAX_SIZE		SIZE_MAX
# define STDIN			0
# define STDOUT			1
# define STDERR			2

# ifndef EOF
#  define EOF 			(-1)
# endif

# ifndef SSIZE_MAX
#  define SSIZE_MAX		0x7fffffffffffffffLL
# endif

# ifndef INT_MAX
#  define INT_MAX		0x7fffffff
# endif

# ifndef UINT_MAX
#  define UINT_MAX		0xffffffffU
# endif

# define MIN_INT		(-2147483648)

/*
**	Data structures.
*/

/*
**	Linked list.
*/
typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

/*
**	Binary tree.
*/
typedef struct			s_btree
{
	struct s_btree		*left;
	struct s_btree		*right;
	void				*item;
}						t_btree;

/*
**	Trie.
*/

# ifndef ASCII_ABC
#  define ASCII_ABC		128
# endif

struct					s_trie
{
	struct trie			*children[ASCII_ABC];
	int					isleaf;
}						t_trie;

/*
**	Hash table.
*/
typedef struct			s_hitem
{
	char				*key;
	char				*value;
}						t_hitem;

typedef struct			s_htab
{
	int					size;
	int					count;
	t_hitem				**items;
}						t_htab;

/*
**	Standart library functions protoripes used in the project.
** But some new functions after passing the project may use forbidden in the
** project functions, like read();
**	Here are the prototipes, of the functions:
**
** void			*malloc(size_t size);
** void			free(void *ptr);
** ssize_t		write(int fildes, const void *buf, size_t nbytes);
*/

/*
** Part 1.
*/
void					*ft_memset(void *dst, int c, size_t size);
void					ft_bzero(void *str, size_t size);
void					*ft_memcpy(void *dst, const void *src, size_t len);
void					*ft_memccpy(void *dst, const void *src, int c,
							size_t size);
void					*ft_memmove(void *dst, const void *src, size_t size);
void					*ft_memchr(const void *str, int c, size_t size);
int						ft_memcmp(const void *min, const void *sub,
		size_t size);
size_t					ft_strlen(const char *str);
char					*ft_strdup(const char *str);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strncpy(char *dst, const char *src, size_t maxlen);
char					*ft_strcat(char *dst, const char *src);
char					*ft_strncat(char *dst, const char *src, size_t size);
size_t					ft_strlcat(char *dst, const char *src, size_t size);
char					*ft_strchr(const char *src, int c);
char					*ft_strrchr(const char *src, int c);
char					*ft_strstr(const char *dst, const char *src);
char					*ft_strnstr(const char *dst, const char *src,
							size_t size);
int						ft_strcmp(const char *min, const char *sub);
int						ft_strncmp(const char *min, const char *sub,
							size_t len);
int						ft_atoi(const char *str);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);

/*
** Part 2.
*/
void					*ft_memalloc(size_t size);
void					ft_memdel(void **address_ptr);
char					*ft_strnew(size_t len);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *str, void (*fptr)(char *));
void					ft_striteri(char *str, void (*fptr)(unsigned int,
							char *));
char					*ft_strmap(const char *str, char (*fptr)(char));
char					*ft_strmapi(const char *str, char (*fptr)(unsigned int,
							char));
int						ft_strequ(const char *min, const char *sub);
int						ft_strnequ(const char *min, const char *sub,
							size_t len);
char					*ft_strsub(const char *str, unsigned int start,
							size_t len);
char					*ft_strjoin(const char *s1, const char *s2);
char					*ft_strtrim(const char *src);
char					**ft_strsplit(const char *str, char c);
char					*ft_itoa(int nbr);
void					ft_putchar(char c);
void					ft_putstr(const char *str);
void					ft_putendl(const char *str);
void					ft_putnbr(int nbr);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(const char *str, int fd);
void					ft_putendl_fd(const char *str, int fd);
void					ft_putnbr_fd(int nbr, int fd);

/*
** Bonus.
*/
t_list					*ft_lstnew(const void *content, size_t content_size);
void					ft_lstdelone(t_list **alst, void (*delptr)(void*,
							size_t));
void					ft_lstdel(t_list **alst, void (*delptr)(void*, size_t));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list *node));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *node));

/*
** Expansion.
*/
int						ft_isspace(int c);
int						ft_isupper(int c);
int						ft_islower(int c);
size_t					ft_strnlen(const char *str, size_t maxlen);
int						ft_power(int base, int pow);
char					*ft_itostr(int nbr, char *str);
char					*ft_strchr_no(const char *str, int c);
char					*ft_strnchr(const char *str, int c, size_t size);
void					*ft_realloc(void *buf1, size_t size1, size_t size2);
void					*ft_memjoin(void *buf1, size_t size1, void *buf2,
							size_t size2);
int						ft_imax(int x, int y);
int						ft_imin(int x, int y);
int						ft_isbinary(void *buf, size_t size);
void					ft_lstaddtip(t_list **head, t_list *new);
t_list					*ft_lstat(t_list *head, size_t nbr);
t_list					*ft_lstlast(t_list *head);
size_t					ft_lstsize(t_list *head);
void					ft_lstremove(t_list **head, t_list *node,
							int (*ft_lstcmp)(t_list *, void *));
int						ft_lstcmp_next(t_list *head, void *node);
void					ft_lstforeach_if(t_list	*node, void (*fptr)(void *),
							void *data_ref, int (*cmp)(void *, void *));
void					ft_lstforeach(t_list *node, void(*fptr)(void *));
void					ft_lstcontentdel(void *content, size_t content_size);
void					ft_lstrev(t_list **head);
t_list					*ft_lstfind(t_list *head, void *data_ref, int (*cmp)());
t_list					*ft_lstfind_prev(t_list *head, t_list *curr);
char					*ft_reverse(char *buffer, int i, int j);
char					*ft_strrev(char *str);
void					ft_swap(void *x, void *y, size_t size);
int						ft_set_nth_bit(int x, int n);
int						ft_unset_nth_bit(int x, int n);
int						ft_set_nth_bit(int x, int n);
int						ft_ispowerof2(int nbr);
size_t					ft_powerof2roundup(long long int nbr);
int						ft_abs(int x);
char					*ft_delim(char **line, char *str, char c);
int						ft_fit_size(ssize_t *bank_size, ssize_t line_size,
							ssize_t step);
int						ft_error(int errno, int line, char *file);
void					*ft_error_ptr(int unused);

/*
** Forbidden in libft project
*/
ssize_t					ft_read_file(int fd, char **line, ssize_t step);

/*
** ft_lststrsplit.c ft_lsttoar.c ft_getfile.c, ft_itoa_base
*/

/*
** BIN_CHECK is number of bites should be cheked if the variable is binary.
** It is for the ft_isbinary() function.
*/
# define BIN_CHECK		1024

/*
**		BUFSIZE			optimum I/O blocksize $>: stat -f %k filename
**		BEST_SIZE		the same
*/
# define BUFSIZE		4096
# define BEST_SIZE		4096

/*
** List of error values for custom error() function. Values are from ERRNO.
**
**	Previous:
**		ONEARG:			only one argument, argc == 2
**
** 		defines:		ft_error.c
** 		NOFILES:		argc < ONEARG
**		TOO_MANY_FILES:	argc > ONEARG
** 		NOTOPEN:		fd < EXIT_SUCCESS
** 		NOTREAD:		read(fd) == -1
** 		NOTCLOSE:		close(fd) != 0
*/

# define ERROR			(-1)
# define FAILURE		(-1)
# define TRUE			(-1)
# define SUCCESS		0
# define ENOENTRY		1
# define EINOUT			2
# define E2BIGENT		3
# define EBADFD			4
# define ENOMEMORY		5
# define ENOACCES		6
# define EINVALARG		7
# define EFILE2BIG		8
# define ENOMSGS		9
# define EOVERFLOW		10

# define NOCHANGES		1

/*
** #define ENOENT			2		No such file or directory
** #define EIO				5		I/O error
** #define E2BIG			7		Arg list too long
** #define EBADF			9		Bad file number
** #define ENOMEM			12		Not enough core
** #define EACCES			13		Permission denied
** #define EINVAL			22		Invalid argument
** #define EFBIG			27		File too large
** #define ENOMSG			35		No message of desired type
** #define EOVERFLOW		139		Value too large for defined data type
**
**
**
** #define EPERM			1		Not super-user
** #define EWOULDBLOCK		EAGAIN	Operation would block
** #define __ELASTERROR		2000	Users can add values starting here
** #define ESRCH			3		No such process
** #define EINTR			4		Interrupted system call
** #define ENXIO			6		No such device or address
** #define ENOEXEC			8		Exec format error
** #define ECHILD			10		No children
** #define EAGAIN			11		No more processes
** #define EFAULT			14		Bad address
** #define ENOTBLK			15		Block device required
** #define EBUSY			16		Mount device busy
** #define EEXIST			17		File exists
** #define EXDEV			18		Cross-device link
** #define ENODEV			19		No such device
** #define ENOTDIR			20		Not a directory
** #define EISDIR			21		Is a directory
** #define ENFILE			23		Too many open files in system
** #define EMFILE			24		Too many open files
** #define ENOTTY			25		Not a typewriter
** #define ETXTBSY			26		Text file busy
** #define ENOSPC			28		No space left on device
** #define ESPIPE			29		Illegal seek
** #define EROFS 			30		Read only file system
** #define EMLINK			31		Too many links
** #define PIPE				32		Broken pipe
** #define EDOM				33		Math arg out of domain of func
** #define ERANGE			34		Math result not representable
** #define EIDRM			36		Identifier removed
** #define ECHRNG			37		Channel number out of range
** #define EL2NSYNC			38		Level 2 not synchronized
** #define EL3HLT			39		Level 3 halted
** #define EL3RST			40		Level 3 reset
** #define ELNRNG			41		Link number out of range
** #define EUNATCH			42		Protocol driver not attached
** #define ENOCSI			43		No CSI structure available
** #define EL2HLT			44		Level 2 halted
** #define EDEADLK			45		Deadlock condition
** #define ENOLCK			46		No record locks available
** #define EBADE			50		Invalid exchange
** #define EBADR			51		Invalid request descriptor
** #define EXFULL			52		Exchange full
** #define ENOANO			53		No anode
** #define EBADRQC			54		Invalid request code
** #define EBADSLT			55		Invalid slot
** #define EDEADLOCK		56		File locking deadlock error
** #define EBFONT			57		Bad font file fmt
** #define ENOSTR			60		Device not a stream
** #define ENODATA			61		No data (for no delay io)
** #define ETIME			62		Timer expired
** #define ENOSR			63		Out of streams resources
** #define ENONET			64		Machine is not on the network
** #define ENOPKG			65		Package not installed
** #define EREMOTE			66		The object is remote
** #define ENOLINK			67		The link has been severed
** #define EADV				68		Advertise error
** #define ESRMNT			69		Srmount error
** #define ECOMM			70		Communication error on send
** #define EPROTO			71		Protocol error
** #define EMULTIHOP		74		Multihop attempted
** #define ELBIN			75		Inode is remote (not really error)
** #define EDOTDOT			76		Cross mount point (not really error)
** #define EBADMSG			77		Trying to read unreadable message
** #define EFTYPE			79		Inappropriate file type or format
** #define ENOTUNIQ			80		Given log. name not unique
** #define EBADFD			81		f.d. invalid for this operation
** #define EREMCHG			82		Remote address changed
** #define ELIBACC			83		Can't access a needed shared lib
** #define ELIBBAD			84		Accessing a corrupted shared lib
** #define ELIBSCN			85		.lib section in a.out corrupted
** #define ELIBMAX			86		Attempting to link in too many libs
** #define ELIBEXEC			87		Attempting to exec a shared library
** #define ENOSYS			88		Function not implemented
** #define ENMFILE	 		89		No more files
** #define ENOTEMPTY		90		Directory not empty
** #define ENAMETOOLONG		91		File or path name too long
** #define ELOOP			92		Too many symbolic links
** #define EOPNOTSUPP		95		Operation not supported on transport
**									endpoint
** #define EPFNOSUPPORT		96		Protocol family not supported
** #define ECONNRESET		104		Connection reset by peer
** #define ENOBUFS			105		No buffer space available
** #define EAFNOSUPPORT		106		Address family not supported by protocol
**									family
** #define EPROTOTYPE		107		Protocol wrong type for socket
** #define ENOTSOCK			108		Socket operation on non-socket
** #define ENOPROTOOPT		109		Protocol not available
** #define ESHUTDOWN		110		Can't send after socket shutdown
** #define ECONNREFUSED		111		Connection refused
** #define EADDRINUSE		112		Address already in use
** #define ECONNABORTED		113		Connection aborted
** #define ENETUNREACH		114		Network is unreachable
** #define ENETDOWN			115		Network interface is not configured
** #define ETIMEDOUT		116		Connection timed out
** #define EHOSTDOWN		117		Host is down
** #define EHOSTUNREACH		118		Host is unreachable
** #define EINPROGRESS		119		Connection already in progress
** #define EALREADY			120		Socket already connected
** #define EDESTADDRREQ		121		Destination address required
** #define EMSGSIZE			122		Message too long
** #define EPROTONOSUPPORT	123		Unknown protocol
** #define ESOCKTNOSUPPORT	124		Socket type not supported
** #define EADDRNOTAVAIL	125		Address not available
** #define ENETRESET		126
** #define EISCONN			127		Socket is already connected
** #define ENOTCONN			128		Socket is not connected
** #define ETOOMANYREFS		129
** #define EPROCLIM			130
** #define EUSERS			131
** #define EDQUOT			132
** #define ESTALE			133
** #define ENOTSUP			134		Not supported
** #define ENOMEDIUM		135		No medium (in tape drive)
** #define ENOSHARE			136		No such host or network path
** #define ECASECLASH		137		Filename exists with different case
** #define EILSEQ			138
*/

#endif
