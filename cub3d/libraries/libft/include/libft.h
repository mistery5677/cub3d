/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thopgood <thopgood@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:24:25 by thopgood          #+#    #+#             */
/*   Updated: 2025/02/06 21:17:03 by thopgood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// standard libraries
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define GNL_ERROR -1

// list struct
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// * Lib C Functions
/** @brief Checks if c is alphabetic.
 *  @param c int representing char to be checked
 *  @return true (1) or false (0)
 */
int					ft_isalpha(int c);

/** @brief Checks if c is numeric.
 *  @param c int representing char to be checked
 *  @return true (1) or false (0)
 */
int					ft_isdigit(int c);

/** @brief Checks if c is alphanumeric.
 *  @param c int representing char to be checked
 *  @return true (1) or false (0)
 */
int					ft_isalnum(int c);

/** @brief Checks if c is ASCII valid char (0 - 127).
 *  @param c int representing char to be checked
 *  @return true (1) or false (0)
 */
int					ft_isascii(int c);

/** @brief Checks if c is printable char incl space.
 *  @param c int representing char to be checked
 *  @return true (1) or false (0)
 */
int					ft_isprint(int c);

/** @brief Calculates length of string s excl null byte ('\0').
 *  @param s string whose length is to be calculated
 *  @return number of bytes in string s
 */
size_t				ft_strlen(const char *s);

/** @brief Fills memory with a constant byte.
 *  @param s Memory block pointed to.
 *  @param c Byte to fill block.
 *  @param n First n bytes to be filled.
 *  @return A pointer to the memory block s
 */
void				*ft_memset(void *s, int c, size_t n);

/** @brief Zero bytes a string - writes '\0' to each byte.
 *  @param s Memory block pointed to.
 *  @param n First n bytes to be filled.
 */
void				ft_bzero(void *s, size_t n);

/** @brief Copies n bytes of memory from src to dest.
 *  @param dest destination for memory copy
 *  @param src source of memory copy
 *  @param n number of bytes to be copied
 *  @return Returns a pointer to dest
 */
void				*ft_memcpy(void *dest, const void *src, size_t n);

/** @brief Copies n bytes of memory from src to dest. Memory areas may overlap.
 *  @param dest destination for memory copy
 *  @param src source of memory copy
 *  @param n number of bytes to be copied
 *  @return Returns a pointer to dest
 */
void				*ft_memmove(void *dest, const void *src, size_t n);

/** @brief Size bound string copy (safer than strlcpy). Guarantees
	NUL-termination. Copies size - 1 chars from src to dst.
 *  @param dst Destination for copied string.
 *  @param src Source string must be NUL-terminated.
 *  @param size number of bytes to be copied including NUL.
 *  @return Returns total length of string it tried to create (length of src).
 */
size_t				ft_strlcpy(char *dst, const char *src, size_t size);

/** @brief Concatenates two strings,
	ensuring NUL-termination and avoiding buffer overflow.
 *  @param dst Destination buffer, which should be a NUL-terminated string.
 *  @param src Source string to be appended to dst.
 *  @param dst_size Total size of the destination buffer,
	including space for the NUL-terminator.
 *	@return The total length of the string it tried to create
	(initial length of dst plus the length of src) so truncation can be clear if
	return value is greater than or equal to dst_size.
 */
size_t				ft_strlcat(char *dst, const char *source, size_t dst_size);

/** @brief Converts a lowercase letter to uppercase.
 *  @param c Character to be converted.
 *  @return (The uppercase equivalent if c is a lowercase letter); otherwise,
	c is returned unchanged.
 */
int					ft_toupper(int c);

/** @brief Converts an uppercase letter to lowercase.
 *  @param c Character to be converted.
 *  @return (The lowercase equivalent if c is an uppercase letter); otherwise,
	c is returned unchanged.
 */
int					ft_tolower(int c);

/** @brief Locates the first occurrence of a character in a string.
 *  @param s String to be searched.
 *  @param c Character to search for.
 * 	@return A pointer to the first occurrence of the character c in the
	string s, or NULL if the character is not found.
 */
char				*ft_strchr(const char *s, int c);

/** @brief Locates the last occurrence of a character in a string.
 *  @param s String to be searched.
 *  @param c Character to search for.
 *  @return A pointer to the last occurrence of the character c in the string s,
	or NULL if the character is not found.
 */
char				*ft_strrchr(const char *s, int c);

/** @brief Compares two strings up to n characters.
 *  @param s1 First string to be compared.
 *  @param s2 Second string to be compared.
 *  @param n Maximum number of characters to compare.
 *  @return An integer greater than, equal to, or less than 0,
	according to whether the first n characters of s1 are greater than,
	equal to, or less than the first n characters of s2.
 */
int					ft_strncmp(const char *s1, const char *s2, size_t n);

/** @brief Scans a block of memory for a specific character.
 *  @param s Memory block to be scanned.
 *  @param c Character to search for.
 *  @param n Number of bytes to scan.
 *  @return A pointer to the first occurrence of the character c in the
	memory block s,
	or NULL if the character is not found.
 */
void				*ft_memchr(const void *s, int c, size_t n);

/** @brief Compares two blocks of memory.
 *  @param s1 First memory block to be compared.
 *  @param s2 Second memory block to be compared.
 *  @param n Number of bytes to compare.
 *  @return An integer greater than, equal to, or less than 0,
	according to whether the first n bytes of s1 are greater than, equal to,
	or less than the first n bytes of s2.
 */
int					ft_memcmp(const void *s1, const void *s2, size_t n);

/** @brief Locates a substring in a string,
	where the search is limited to len characters.
 *  @param big String to be searched.
 *  @param little Substring to search for.
 *  @param len Maximum number of characters to search.
 *  @return A pointer to the beginning of the located substring,
	or NULL if the substring is not found within the first len characters.
 */
char				*ft_strnstr(const char *big, const char *little,
						size_t len);

/** @brief Converts a string to an integer.
 *  @param nptr String to be converted.
 *  @return The converted integer.
 */
int					ft_atoi(const char *nptr);

/** @brief Allocates memory for an array of nitems,
	each of them size bytes long,
	and initializes all bytes in the allocated storage to zero.
 *  @param nitems Number of elements.
 *  @param size Size of each element.
 *  @return A pointer to the allocated memory, or NULL if the allocation fails.
 */
void				*ft_calloc(size_t nitems, size_t size);

/** @brief Duplicates a string by allocating memory and copying the original
	string.
 *  @param s String to be duplicated.
 *  @return A pointer to the duplicated string,
	or NULL if memory allocation fails.
 */
char				*ft_strdup(const char *s);

// * Additional Functions
/** @brief Allocates memory for a new string which is a substring of s.
 *  @param s String from which the substring is to be created.
 *  @param start Index of the first character of the substring.
	If start is beyond the end of the string, an empty string is returned.
 *  @param len Maximum length of the substring.
 *  @return A pointer to new string, or NULL if memory allocation fails.
 */
char				*ft_substr(char const *s, unsigned int start, size_t len);

/** @brief Allocates memory for a new string s1 + s2.
 *  @param s1 First string to be concatenated.
 *  @param s2 Second string to be concatenated.
 *  @return A pointer to the new string, or NULL if memory allocation fails.
 */
char				*ft_strjoin(char const *s1, char const *s2);

/** @brief returns allocated string from variable number of strings
 */
char				*join_var(int count, ...);

/** @brief Allocates memory for a new string which is a copy of s1,
	with the characters in set trimmed from the beginning and end
 *  @param s1 String to be trimmed.
 *  @param set Set of characters to be trimmed.
 *  @return A pointer to the new string, or NULL if memory allocation fails.
 */
char				*ft_strtrim(char const *s1, char const *set);

/** @brief Allocates memory for an array of strings obtained by splitting s
	using the character c as a delimiter.
 *  @param s String to be split.
 *  @param c Delimiting character.
 *  @return A pointer to the array of new strings,
	or NULL if memory allocation fails.
 */
char				**ft_split(char const *s, char c);

/** @brief Allocates memory for unteger to ASCII conversion
 *  @param n Integer to be converted.
 *  @return A pointer to the new string, or NULL if memory allocation fails.
 */
char				*ft_itoa(int n);

/** @brief Allocates memory for a new string obtained by applying the function f
	to each character of the string s.
 *  @param s String to be iterated.
 *  @param f Function to apply to each character.
 *  @return A pointer to the new string, or NULL if memory allocation fails.
 */
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/** @brief Applies the function f to each character of the string s.
 *  @param s String to be iterated.
 *  @param f Function to apply to each character.
 */
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

/** @brief Puts the character c to a chosen file descriptor.
 *  @param c Character to be output.
 *  @param fd File descriptor.
 */
void				ft_putchar_fd(char c, int fd);

/** @brief Outputs the string s to a chosen file descriptor.
 *  @param s String to be output.
 *  @param fd File descriptor.
 */
void				ft_putstr_fd(char *s, int fd);

/** @brief Outputs the string s to a chosen file descriptor followed by
	newline.
 *  @param s String to be output.
 *  @param fd File descriptor.
 */
void				ft_putendl_fd(char *s, int fd);

/** @brief Outputs the integer n to a chosen file descriptor.
 *  @param n Integer to be output.
 *  @param fd File descriptor.
 */
void				ft_putnbr_fd(int n, int fd);

// * Bonus Functions
/** @brief Allocates memory for a new element of a linked list.
 *  @param content Data to be stored in the new element.
 *  @return A pointer to the new element, or NULL if memory allocation fails.
 */
t_list				*ft_lstnew(void *content);

/** @brief Adds a new element to the beginning of a linked list.
 *  @param lst Address of a pointer to the first element of the list.
 *  @param new New element to be added.
 */
void				ft_lstadd_front(t_list **lst, t_list *new);

/** @brief Counts the number of elements in a linked list.
 *  @param lst First element of the list.
 *  @return The number of elements in the list.
 */
int					ft_lstsize(t_list *lst);

/** @brief Returns the last element of a linked list.
 *  @param lst First element of the list.
 *  @return The last element of the list.
 */
t_list				*ft_lstlast(t_list *lst);

/** @brief Adds a new element to the end of a linked list.
 *  @param lst Address of a pointer to the first element of the list.
 *  @param new New element to be added.
 */
void				ft_lstadd_back(t_list **lst, t_list *new);

/** @brief Deletes an element and frees the memory it occupied.
 *  @param lst Element to be deleted.
 *  @param del Function to free the memory of the element's content.
 */
void				ft_lstdelone(t_list *lst, void (*del)(void *));

/** @brief Deletes all elements of a linked list and frees the memory they
	occupied.
 *  @param lst Address of a pointer to the first element of the list.
 *  @param del Function to free the memory of an element's content.
 */
void				ft_lstclear(t_list **lst, void (*del)(void *));

/** @brief Iterates over a linked list and applies the function f to each
	element.
 *  @param lst First element of the list.
 *  @param f Function to apply to each element.
 */
void				ft_lstiter(t_list *lst, void (*f)(void *));

/** @brief Iterates over a linked list and applies the function f to each
	element, creating a new list with the results.
 *  @param lst First element of the list.
 *  @param f Function to apply to each element.
 *  @param del Function to free the memory of an element's content.
 *  @return A pointer to the first element of the new list,
	or NULL if memory allocation fails.
 */
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

// * Extra Functions

/** @brief Checks if c is a whitespace character.
 *  @param c Character to be checked.
 *  @return true (1) or false (0).
 */
int					ft_isspace(char c);

/** @brief Outputs an integer in a chosen base to a file descriptor.
 *  @param n Integer to be output.
 *  @param base Base to be used for the output.
 *  @param fd File descriptor.
 */
void				ft_putbase_fd(int n, const char *base, int fd);

/** @brief Returns absolute value of long n
 */
long				ft_abs(long n);

/** @brief Gets next line from file descriptor.
 *  @param fd File descriptor to read from.
 *  @param line Address of a pointer to the line read.
 *  @return 1 if successful, 0 if EOF was reached, -1 if an error occurred.
 */
int					get_next_line(int fd, char **line);

/** @brief String pointer break. Returns pointer to first occurrence
	of any char from s2 in s1
	@param s1 String to be searched.
	@param s2 String containing characters to search for.
	@return Pointer to first occurrence of any char from s2 in s1
 */
char				*ft_strpbrk(const char *s1, const char *s2);

/** @brief Counts the number of words in a string.
 *  @param str String to be counted.
 *  @param set Set of characters to be used as delimiters.
 *  @return The number of words in the string.
 */
int					count_words(char *str, char *set);

// * ft_printf Functions
# define HEXUPPER_BASE "0123456789ABCDEF"
# define HEXLOWER_BASE "0123456789abcdef"
# define HEX_PREF "0x"
# define NIL_MSG "(nil)"
# define DEC_BASE "0123456789"
# define NULL_MSG "(null)"

int					ft_printdigit(long n, const char *base);
int					ft_printudigit(unsigned long long n, const char *base);
int					ft_printhex(unsigned long long n, char c);
int					ft_printptr(unsigned long long ptr);
int					ft_printdec(long n);
int					ft_printchar(int c);
int					ft_printstr(char *str);
int					ft_printf(const char *format, ...);

// *ft_dprintf Functions
int					ft_dprintdigit(int fd, long n, const char *base);
int					ft_dprintudigit(int fd, unsigned long long n,
						const char *base);
int					ft_dprinthex(int fd, unsigned long long n, char c);
int					ft_dprintptr(int fd, unsigned long long ptr);
int					ft_dprintdec(int fd, long n);
int					ft_dprintchar(int fd, int c);
int					ft_dprintstr(int fd, char *str);
int					ft_dprintf(int fd, const char *format, ...);

// * More *
/** @brief Like strchr but excludes NUL.
 * Locates the first occurrence of a character in a string.
 *  @param s String to be searched.
 *  @param c Character to search for.
 * 	@return A pointer to the first occurrence of the character c in the
	string s, or NULL if the character is not found.
 */
char				*ft_strchr_no_null(const char *s, int c);

int					ft_array_size(char **array);
int					ft_max(int a, int b);
int					ft_min(int a, int b);
void				safe_free(char **ptr);
void				safe_free_array(char ***arr);
void				free_array(char **arr);
int					arr_length(char **arr);
size_t				ft_strncpy(char *dest, const char *src, size_t dstsize);

#endif
