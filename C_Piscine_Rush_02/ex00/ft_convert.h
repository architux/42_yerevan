/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@student.42yerevan.am    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 15:35:58 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/14 23:28:05 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERT_H
# define FT_CONVERT_H

# define USECASE_A 2
# define USECASE_B 3

# define MAPPING_FILE_DELIMITER ':'
# define REQUIRED_MAPPING_FILE_NAME ".default.dict"
# define REQUIRED_MAPPINGS_COUNT 41
# define REQUIRED_MAPPINGS_MAX_KEY_LEN 36
# define DEFAULT_MAPPING_FILE_NAME "numbers.dict"

# define LAST_ERROR_FILE_NAME "last_error.file"
# define ARGS_ERROR_TEXT "Error\n"
# define ARGS_ERROR_LEN 6
# define ARGS_ERROR_EXIT_CODE 1
# define MAPPING_ERROR_TEXT "Dict Error\n"
# define MAPPING_ERROR_LEN 11
# define MAPPING_ERROR_EXIT_CODE 2

# define SUCCESS_EXIT_CODE 0

typedef struct s_mapping
{
	char	*key;
	char	*value;
}	t_mapping;

/* errors.c */
void		error_file_init(void);
int			get_last_error(void);
void		set_last_error(int error);
int			handle_error(int code);

/* validation.c */
int			validate_number(char **number);

/* dict_parser.c */
int			count_lines(char *content);
char		**split_lines(char *content, int *line_count, int i, int j);
int			parse_mapping_line(char *line, char **key, char **value);
int			free_stuff(char **lines, int line_count,
				t_mapping *mappings, int *count);
t_mapping	*parse_dictionary(char *path, int *count);

/* dict_validation.c */
int			check_duplicate_keys(t_mapping *mappings, int count);
int			check_required_mappings(t_mapping *dict, int dict_count,
				t_mapping *req, int req_count);
int			validate_dictionary(t_mapping *mappings, int count);
int			can_convert_number(char *number, t_mapping *mappings, int count);

/* conversion.c */
char		*find_mapping(t_mapping *mappings, int count, char *key);
char		*convert_hundreds(int *arr, t_mapping *mappings, int count);
char		*convert_triplet(char *triplet, t_mapping *mappings, int count);
char		*find_scale_name(t_mapping *mappings, int count, int group_index);
char		*convert_number(char *number, t_mapping *mappings, int count);

/* process.c */
int			ft_strlen(char *str);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strdup(char *src);
char		*process_conversion(char *dict_path, char *number);
int			print_result(int argc, char *dict_path, char *number_str);

/* helpers.c */
char		*extract_substring(char *str, int start, int len);
int			is_empty_line(char *line);
void		append_with_space(char *dest, char *src);
char		*pad_number(char *number);
void		extract_triplet(char *padded, int group_index, char *triplet);

/* helpers2.c */
void		temp_func(t_mapping *mappings, int count, char *key, char *result);
void		convert_tens_ones(int *arr, char *result,
				t_mapping *mappings, int count);
void		process_triplet(char *triplet, int *arr, char *result,
				t_mapping *mappings);
void		free_lines(char **lines, int count);
void		free_mappings(t_mapping *mappings, int count);

/* helpers_dict.c */
int			read_file(char *path, char **content, int total);
int			validate_dict_key(char *key);
int			validate_dict_keys(t_mapping *mappings, int count);
int			validate_acceptable_key(char *s);
int			check_acceptable_keys(t_mapping *mappings, int count);

/* helpers_val.c */
char		*get_result(char *result, int end, int i, char *str);
char		*trim_whitespace(char *str);
int			is_digit(char c);
char		*strip_leading_zeros(char *str);
int			check_number_format(char *str);

#endif