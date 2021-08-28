#!/bin/bash
#
#	* File      : t.sh
#	* Author    : sunowsir
#	* Mail      : sunowsir@163.com
#	* Creation  : Sun 05 Apr 2020 03:22:20 PM CST

# 在这个数组中加入你想要执行的命令，注意把0号和1号删掉，
# 注意：如果命令中有特殊字符，比如："gnome-terminal -e \"echo test\"，需要加反斜杠
cmd_str=( \
	[0]='konsole' \
	[1]='konsole' \
	)

cmd_pid=()

# =============================================================

function run_cmd() {
	for ((i = 0; i < ${#cmd_str[@]}; i++))
	do
		echo "${cmd_str[i]}"
		
		# 将字符串当作命令执行，如果需要使用gnome-terminal这种新开终端然后 -e后面加需要执行的命令，
		# 那么可以把-e 执行的命令放到上面的数组中，下面的eval中放其他的，
		# eval "gnome-terminal --window -t \"Mongodb\" -e ${cmd_str[i]} --tab -t .... "
		eval "${cmd_str[i]} &"
		
		cmd_pid[i]="$(pgrep "${cmd_str[i]}" | tail -1)"

	done

	return "${?}"
}

function stop_cmd() {
	sleep 0.5
	for ((i = 0; i < ${#cmd_pid[@]}; i++));
	do
		kill "${cmd_pid[i]}"
	done
	
	return "${?}"
}

# =============================================================

function main() {
	# 后台执行cmd_str中的所有命令
	run_cmd

	while true;
	do
		read -r ope_cmd

		# 输入stop杀掉所有命令
		if [[ "${ope_cmd}" == "stop" ]];
		then
			stop_cmd
			break;
		fi

	done

	return "${?}"
}

# =============================================================

main "${@}"
exit "${?}"
