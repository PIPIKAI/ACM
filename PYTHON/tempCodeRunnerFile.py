id_num = re.compile("z:'(.*?)'").findall(response.text)[0]
        # name = re.compile("n:'(.*?)'").findall(response.text)[0]
        # school = re.compile("x:'(.*?)'").findall(response.text)[0]
        # score = re.compile("s:(.*?),").findall(response.text)[0]
        # listening = re.compile("l:(.*?),").findall(response.text)[0]
        # reading = re.compile("r:(.*?),").findall(response.text)[0]
        # writing = re.compile("w:(.*?),").findall(response.text)[0]
        # rank = re.compile("kys:'(.*?)'").findall(response.text)[0]
        # if level=='1':
        #     print("\n====================\n\n四级笔试成绩：")
        # elif level=='2':
        #     print("\n====================\n\n六级笔试成绩：")
        # print("准考证号：" + str(id_num))
        # print("姓名：" + str(name))
        # print("学校：" + str(school))
        # print("总分：" + str(score))
        # print("听力：" + str(listening))
        # print("阅读：" + str(reading))
        # print("写作与翻译：" + str(writing))
        # print("等级：" + str(rank))