#!/usr/bin/python3
# -*- coding: utf-8 -*-
# __author__: kainhuck

'''
爬虫具有时效,时间长可能无法正常工作.

只能爬取视频,无法爬取番剧和电影.

后面再写番剧的爬虫吧...
'''

import requests
import re
import json
import os

if not os.path.exists("Midea"):
    os.mkdir("Midea")


def downloader(Video, filename, title):
    chunk_size = 1024
    size = 0
    content_size = int(Video.headers['content-length'])
    if Video.status_code == 200:
        print((title + '---[文件大小]:%0.2fMB') % (content_size / chunk_size / 1024))
        with open(filename, 'wb') as file:
            for data in Video.iter_content(chunk_size=chunk_size):
                file.write(data)
                size += len(data)
                print(
                    '\r' + '[下载进度]:%s%.2f%%' % ('█' * int(size * 50 / content_size), float(size / content_size * 100)),
                    end='')
            print('')


def main(url):
    headers = {
        "Origin": "https://www.bilibili.com",
        "Referer": url,
        "User-Agent": "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/75.0.3770.100 Safari/537.36"
    }

    r = requests.get(url, headers=headers)

    title = re.findall('<title data-vue-meta="true">(.*?)_', r.text)[0]
    info_dict = json.loads(re.findall("window.__playinfo__=(.+?)</script>", r.text)[0])
    # print(re.findall("window.__playinfo__=(.+?)</script>", r.text)[0])
    try:
        # 视频清晰度
        Video_definition = {
            16: "360P",
            32: "480P",
            64: "720P",
            80: "1080P",
            112: "1080P+"
        }

        choose_dict = {
            16: 0,
            32: 1,
            64: 2,
            80: 3,
            112: 4
        }

        roll_definition = {
            0: "360P",
            1: "480P",
            2: "720P",
            3: "1080P",
            4: "1080P+"
        }

        video_url_list = info_dict['data']['dash']['video']
        # pprint(info_dict['data']['dash']['video'])

        # 打印信息
        print("请选择视频清晰度:")
        # 有些情况原代码里有重复的信息,这是为了去重用
        flag = []
        for each in video_url_list:
            id_ = each['id']
            if id_ == 16:
                flag.append(flag)
            if len(flag) == 2:
                break
            print(choose_dict.get(id_, None), "->", Video_definition.get(id_, None))

        choose = int(input("请输入: "))
        print("\n开始下载\n")

        # 获取下载链接
        mp4_download_url = video_url_list[choose]['baseUrl']
        mp4_filename = "Midea" + os.sep + title + roll_definition.get(choose, None) + ".mp4"
        video = requests.get(mp4_download_url, headers=headers, stream=True)
        # 开始下载视频
        downloader(video, mp4_filename, title + "-视频")

        # 音频文件
        audio_url_list = info_dict['data']['dash']['audio']
        mp3_download_url = audio_url_list[0]['baseUrl']
        mp3 = requests.get(mp3_download_url, headers=headers, stream=True)
        mp3_filename = "Midea" + os.sep + title + ".mp3"
        # 开始下载音频
        downloader(mp3, mp3_filename, title + "-音频")
    except KeyError:
        # pprint(info_dict)
        downloadUrl = info_dict['data']['durl'][0]['url']
        video = requests.get(downloadUrl, headers=headers, stream=True)
        downloader(video, "Midea" + os.sep + title + ".mp4", title)
    except:
        print("爬取失败", url)
    finally:
        print("请在当前目录下的 -> Midea <- 文件夹下查看下载结果")


if __name__ == '__main__':
    print('\n')
    print(
        r'                        //                                                                                  ')
    print(
        r'            \\         //                                                                                   ')
    print(
        r'             \\       //                                                                                    ')
    print(
        r'       ##DDDDDDDDDDDDDDDDDDDDDD##                                                                           ')
    print(
        r'       ## DDDDDDDDDDDDDDDDDDDD ##   ________   ___   ___        ___   ________   ___   ___        ___       ')
    print(
        r'       ## hh                hh ##   |\   __  \ |\  \ |\  \      |\  \ |\   __  \ |\  \ |\  \      |\  \     ')
    print(
        r'       ## hh    //    \\    hh ##   \ \  \|\ /_\ \  \\ \  \     \ \  \\ \  \|\ /_\ \  \\ \  \     \ \  \    ')
    print(
        r'       ## hh   //      \\   hh ##    \ \   __  \\ \  \\ \  \     \ \  \\ \   __  \\ \  \\ \  \     \ \  \   ')
    print(
        r'       ## hh                hh ##     \ \  \|\  \\ \  \\ \  \____ \ \  \\ \  \|\  \\ \  \\ \  \____ \ \  \  ')
    print(
        r'       ## hh      wwww      hh ##      \ \_______\\ \__\\ \_______\\ \__\\ \_______\\ \__\\ \_______\\ \__\ ')
    print(
        r'       ## hh                hh ##       \|_______| \|__| \|_______| \|__| \|_______| \|__| \|_______| \|__| ')
    print(
        r'       ## MMMMMMMMMMMMMMMMMMMM ##                                                                           ')
    print(
        r'       ##MMMMMMMMMMMMMMMMMMMMMM##             bilibili video downloader release 0.0.1. Powered by kainhuck  ')
    print(
        r'            \/            \/                                                                                ')

    url = input("\n请输入下载视频的链接: ")
    main(url)
