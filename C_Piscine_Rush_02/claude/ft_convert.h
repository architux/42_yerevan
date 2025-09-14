/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvasilev <mvasilev@42yerevan.am>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 15:35:58 by mvasilev          #+#    #+#             */
/*   Updated: 2025/09/14 15:36:24 by mvasilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERT_H
# define FT_CONVERT_H

typedef struct s_mapping
{
	char	*key;
	char	*value;
}	t_mapping;

/* main.c */
int			ft_strlen(char *str);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strdup(char *src);
int			handle_error(int code);

/* validation.c */
char		*trim_whitespace(char *str);
int			is_digit(char c);
char		*strip_leading_zeros(char *str);
int			check_number_format(char *str);
int			validate_number(char **number);

/* dict_parser.c */
int			read_file(char *path, char **content);
int			count_lines(char *content);
char		**split_lines(char *content, int *line_count);
int			parse_mapping_line(char *line, char **key, char **value);
t_mapping	*parse_dictionary(char *path, int *count);

/* dict_validation.c */
int			validate_dict_key(char *key);
int			check_duplicate_keys(t_mapping *mappings, int count);
int			check_required_mappings(t_mapping *dict, int dict_count,
				t_mapping *req, int req_count);
int			validate_dictionary(t_mapping *mappings, int count);
int			can_convert_number(char *number, t_mapping *mappings, int count);

/* conversion.c */
char		*find_mapping(t_mapping *mappings, int count, char *key);
char		*convert_hundreds(int h, int t, int o, t_mapping *mappings,
				int count);
char		*convert_triplet(char *triplet, t_mapping *mappings, int count);
char		*find_scale_name(t_mapping *mappings, int count, int group_index);
char		*convert_number(char *number, t_mapping *mappings, int count);

/* helpers.c */
char		*extract_substring(char *str, int start, int len);
int			is_empty_line(char *line);
void		append_with_space(char *dest, char *src);
char		*pad_number(char *number);
void		extract_triplet(char *padded, int group_index, char *triplet);

/* helpers2.c */
void		convert_tens_ones(int t, int o, char *result,
				t_mapping *mappings, int count);
void		process_triplet(char *triplet, int group_index, char *result,
				t_mapping *mappings, int count);
void		free_lines(char **lines, int count);
void		free_mappings(t_mapping *mappings, int count);

/* process.c */
int			get_last_error(void);
void		set_last_error(int error);
char		*process_conversion(char *dict_path, char *number);

#endif