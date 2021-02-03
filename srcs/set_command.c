#include "lemin.h"

/*
 * вернет 0, если команда неизвестна (фактически пропустит ее)
 * вернет -1, если старт/финиш был найден, но пришла повторная команда
 * вернет 2, если была найдена команда старта и индекс стартовой комнаты
 * не был установлен
 * вернет 3, если была найдена команда финиша и индекс последней комнаты
 * не был установлен
 */

static int	check_command(char *line, t_input *input)
{
	int		start;
	int		end;

	start = ft_strequ(line, "##start");
	end = ft_strequ(line, "##end");
	if (!start && !end)
		return (0);
	if (start && input->start_id != -1)
		return (-1);
	if (end && input->end_id != -1)
		return (-1);
	if (start && input->start_id == -1)
		return (2);
	if (end && input->end_id == -1)
		return (3);
	return (1);
}

/*
 * определяет команды старт и энд и меняет переключатель ожиданий
 * на координаты соответствующей комнаты
 */

void		set_command(char *line, t_input *input)
{
	int		check;

	check = check_command(line, input);
	if (check < 0)
		error(ES_DUPS);
	else if (check == 2)
		input->expected = START;
	else if (check == 3)
		input->expected = END;
}
