#!/bin/bash


info() {

    zenity --forms \
        --title="linux校园网客户端--确认登录信息" \
        --text="学号: $id \n密码: $pd" \
        --ok-label="确认" \
        --cancel-label="返回"
    #yes:0  no:1

    return $?
}

input() {

    result=` \
        zenity --forms \
        --title="linux校园网客户端--登录" \
        --text="    请输入您的学号和密码" \
        --add-entry="学号:" \
        --add-password="请输入密码:" \
        --ok-label="确认" \
        --cancel-label="取消" \

        `

    judges=$?

    case $judges in

        0)

            id=${result%|*}
            pd=${result#*|}

            echo $result >> usr.txt

            info $id $pd;

            judge=$?

            case $judge in

                0)
                    fun $id $pd $judge;;
                1)
                    input;;
            esac
        ;;
    esac

}


input;

exit;
