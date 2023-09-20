/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: everonel <everonel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 10:33:59 by everonel          #+#    #+#             */
/*   Updated: 2023/09/18 00:35:17 by everonel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# define RESET		"\033[0m"
# define BOLD		"\033[1m"
# define BLACK		"\033[30m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"

# define B_BLACK		"\033[40m"
# define B_RED			"\033[41m"
# define B_GREEN		"\033[42m"
# define B_YELLOW		"\033[43m"
# define B_BLUE			"\033[44m"
# define B_MAGENTA		"\033[45m"
# define B_CYAN			"\033[46m"
# define B_WHITE		"\033[47m"

# define U_BLACK		"\033[4;30m"
# define U_RED			"\033[4;31m"
# define U_GREEN		"\033[4;32m"
# define U_YELLOW		"\033[4;33m"
# define U_BLUE			"\033[4;34m"
# define U_MAGENTA		"\033[4;35m"
# define U_CYAN			"\033[4;36m"
# define U_WHITE		"\033[4;37m"

# define BOLD_BLACK		"\033[1;30m"
# define BOLD_RED		"\033[1;31m"
# define BOLD_GREEN		"\033[1;32m"
# define BOLD_YELLOW	"\033[1;33m"
# define BOLD_BLUE		"\033[1;34m"
# define BOLD_MAGENTA	"\033[1;35m"
# define BOLD_CYAN		"\033[1;36m"
# define BOLD_WHITE		"\033[1;37m"

# define BG_BLACK		"\033[40m"
# define BG_RED			"\033[41m"
# define BG_GREEN		"\033[42m"
# define BG_YELLOW		"\033[43m"
# define BG_BLUE		"\033[44m"
# define BG_MAGENTA		"\033[45m"
# define BG_CYAN		"\033[46m"
# define BG_WHITE		"\033[47m"

# define BG_BOLD_BLACK		"\033[1;40m"
# define BG_BOLD_RED		"\033[1;41m"
# define BG_BOLD_GREEN		"\033[1;42m"
# define BG_BOLD_YELLOW		"\033[1;43m"
# define BG_BOLD_BLUE		"\033[1;44m"
# define BG_BOLD_MAGENTA	"\033[1;45m"
# define BG_BOLD_CYAN		"\033[1;46m"
# define BG_BOLD_WHITE		"\033[1;47m"

# define ITALIC_BLACK		"\033[3;30m"
# define ITALIC_RED			"\033[3;31m"
# define ITALIC_GREEN		"\033[3;32m"
# define ITALIC_YELLOW		"\033[3;33m"
# define ITALIC_BLUE		"\033[3;34m"
# define ITALIC_MAGENTA		"\033[3;35m"
# define ITALIC_CYAN		"\033[3;36m"
# define ITALIC_WHITE		"\033[3;37m"

# define UNDERLINE_BLACK	"\033[4;30m"
# define UNDERLINE_RED		"\033[4;31m"
# define UNDERLINE_GREEN	"\033[4;32m"
# define UNDERLINE_YELLOW	"\033[4;33m"
# define UNDERLINE_BLUE		"\033[4;34m"
# define UNDERLINE_MAGENTA	"\033[4;35m"
# define UNDERLINE_CYAN		"\033[4;36m"
# define UNDERLINE_WHITE	"\033[4;37m"

# define BG_ITALIC_BLACK	"\033[3;40m"
# define BG_ITALIC_RED		"\033[3;41m"
# define BG_ITALIC_GREEN	"\033[3;42m"
# define BG_ITALIC_YELLOW	"\033[3;43m"
# define BG_ITALIC_BLUE		"\033[3;44m"
# define BG_ITALIC_MAGENTA	"\033[3;45m"
# define BG_ITALIC_CYAN		"\033[3;46m"
# define BG_ITALIC_WHITE	"\033[3;47m"

# define BG_UNDERLINE_BLACK	"\033[4;40m"
# define BG_UNDERLINE_RED	"\033[4;41m"
# define BG_UNDERLINE_GREEN	"\033[4;42m"
# define BG_UNDERLINE_YELLOW	"\033[4;43m"
# define BG_UNDERLINE_BLUE	"\033[4;44m"
# define BG_UNDERLINE_MAGENTA	"\033[4;45m"
# define BG_UNDERLINE_CYAN	"\033[4;46m"
# define BG_UNDERLINE_WHITE	"\033[4;47m"

# define BG_BOLD_ITALIC_BLACK		"\033[1;3;40m"
# define BG_BOLD_ITALIC_RED			"\033[1;3;41m"
# define BG_BOLD_ITALIC_GREEN		"\033[1;3;42m"
# define BG_BOLD_ITALIC_YELLOW		"\033[1;3;43m"
# define BG_BOLD_ITALIC_BLUE		"\033[1;3;44m"
# define BG_BOLD_ITALIC_MAGENTA		"\033[1;3;45m"
# define BG_BOLD_ITALIC_CYAN		"\033[1;3;46m"
# define BG_BOLD_ITALIC_WHITE		"\033[1;3;47m"

# define BG_BOLD_UNDERLINE_BLACK	"\033[1;4;40m"
# define BG_BOLD_UNDERLINE_RED		"\033[1;4;41m"
# define BG_BOLD_UNDERLINE_GREEN	"\033[1;4;42m"
# define BG_BOLD_UNDERLINE_YELLOW	"\033[1;4;43m"
# define BG_BOLD_UNDERLINE_BLUE		"\033[1;4;44m"
# define BG_BOLD_UNDERLINE_MAGENTA	"\033[1;4;45m"
# define BG_BOLD_UNDERLINE_CYAN		"\033[1;4;46m"
# define BG_BOLD_UNDERLINE_WHITE	"\033[1;4;47m"

# define BG_ITALIC_UNDERLINE_BLACK	"\033[3;4;40m"
# define BG_ITALIC_UNDERLINE_RED	"\033[3;4;41m"
# define BG_ITALIC_UNDERLINE_GREEN	"\033[3;4;42m"
# define BG_ITALIC_UNDERLINE_YELLOW	"\033[3;4;43m"
# define BG_ITALIC_UNDERLINE_BLUE	"\033[3;4;44m"
# define BG_ITALIC_UNDERLINE_MAGENTA	"\033[3;4;45m"
# define BG_ITALIC_UNDERLINE_CYAN	"\033[3;4;46m"
# define BG_ITALIC_UNDERLINE_WHITE	"\033[3;4;47m"

# define BG_BOLD_ITALIC_UNDERLINE_BLACK		"\033[1;3;4;40m"
# define BG_BOLD_ITALIC_UNDERLINE_RED		"\033[1;3;4;41m"
# define BG_BOLD_ITALIC_UNDERLINE_GREEN		"\033[1;3;4;42m"
# define BG_BOLD_ITALIC_UNDERLINE_YELLOW	"\033[1;3;4;43m"
# define BG_BOLD_ITALIC_UNDERLINE_BLUE		"\033[1;3;4;44m"
# define BG_BOLD_ITALIC_UNDERLINE_MAGENTA	"\033[1;3;4;45m"
# define BG_BOLD_ITALIC_UNDERLINE_CYAN		"\033[1;3;4;46m"
# define BG_BOLD_ITALIC_UNDERLINE_WHITE		"\033[1;3;4;47m"

# define BOLD_ITALIC_BLACK		            "\033[1;3;30m"
# define BOLD_ITALIC_RED		            "\033[1;3;31m"
# define BOLD_ITALIC_GREEN		            "\033[1;3;32m"
# define BOLD_ITALIC_YELLOW		            "\033[1;3;33m"
# define BOLD_ITALIC_BLUE		            "\033[1;3;34m"
# define BOLD_ITALIC_MAGENTA		        "\033[1;3;35m"
# define BOLD_ITALIC_CYAN		            "\033[1;3;36m"
# define BOLD_ITALIC_WHITE		            "\033[1;3;37m"



#endif