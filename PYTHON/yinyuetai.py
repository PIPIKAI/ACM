'''
时间：2019-7-14
目标网址：http://www.e5a5x.com/
采集需求：获得所有源代码
作者：钟志锴
'''
import requests
import urllib.request
import os
import urllib.error
import socket
import re

keyword = '邓紫棋'
timeout = 3.0
socket.setdefaulttimeout(timeout)

def clean_title(filename):
    # 将非法字符替换成'-'
    title = re.sub('[\/:*?"<>|]', '-', filename)
    return title
class YinYueTaiSpider(object):
    def get_index(self, url):
        try:
            response = requests.get(url)
            if response.status_code == 200:
                json = response.json()
                return json
            return None
        except ConnectionError:
            return None

    def get_page_count(self):
        # 获取mv总页数
        get_page_url = 'http://soapi.yinyuetai.com/search/video-search?keyword={0}&pageIndex=1&pageSize=24'\
            .format(keyword)  # keyword是艺人名
        try:
            response = requests.get(get_page_url)
            if response.status_code == 200:
                json = response.json()
                page_count = json.get('pageInfo')['pageCount']  # 获取总页数
                return page_count
            return None
        except ConnectionError:
            return None

    def get_mv_info(self, json):
        # 获取mv的id、标题
        if json.get('videos'):
            items = json.get('videos')['data']
            for item in items:
                video_id = item.get('id')
                title = item.get('title')
                yield {
                    'video_id': video_id,
                    'title': title,
                }

    def get_mv_source_url(self, video_id):
        # 构造mv真实地址
        mv_source_url = 'http://www.yinyuetai.com/api/info/get-video-urls?flex=true&videoId={}'.format(video_id)
        json_dict = requests.get(mv_source_url).json()
        mv_source_dict = {
            'SD_MV': json_dict["hdVideoUrl"] if "hdVideoUrl" in json_dict else None,
            'HD_MV': json_dict["hcVideoUrl"] if "hcVideoUrl" in json_dict else None,
            'FHD_MV': json_dict["heVideoUrl"] if "heVideoUrl" in json_dict else None,
        }

        mv_source_list = []

        for key, value in mv_source_dict.items():
            if value is not None:
                mv_source_list.append(value)
        return mv_source_list

    def download_mv(self, mv_source_list, title, video_id):  # 下载最高品质的视频
        # 创建存放视频的文件夹
        file = 'C:/Users/kiass/Desktop/{}/'.format(keyword)
        if not os.path.exists(file):
            os.mkdir(file)
            print('创建文件夹：', file)

        # 处理下载过程中的异常
        try:
            # 判断视频文件是否存在，并且给视频文件名做处理，将不合法的字符用'-'替代
            if not os.path.exists(file + clean_title(title) + '-' + str(video_id) + '.mp4'):
                print('Start Download MV：' + title + '...：', mv_source_list[-1])
                urllib.request.urlretrieve(url=mv_source_list[-1], filename=file + clean_title(title) + '-' + str(video_id) + '.mp4')
                print('MV Download Success：', title)
            else:
                print('MV：{}-已存在'.format(clean_title(title)))
        except socket.timeout:
            # 解决下载时间过长甚至出现死循环的情况
            count = 1
            while count <= 5:
                try:
                    urllib.request.urlretrieve(url=mv_source_list[-1], filename=file + clean_title(title) + '-' + str(video_id) + '.mp4')
                    print('MV Download Success：', title)
                    break
                except socket.timeout:
                    err_info = 'Reloading for %d time' % count if count == 1 else 'Reloading for %d times' % count
                    print(err_info)
                    count += 1
                if count > 5:
                    print("Downloading MV Failed!")

    def main(self):
        page_count = self.get_page_count()
        mv_count = 0
        for page in range(1, 2):
            print('Crawl Page:', page)
            url = 'http://soapi.yinyuetai.com/search/video-search?keyword={0}&pageIndex={1}&pageSize=24'.format(keyword,page)
            json = self.get_index(url)
            print(json)
            '''
            for item in self.get_mv_info(json):
                mv_count += 1
                video_id = item['video_id']
                title = item['title']
                mv_source_list = self.get_mv_source_url(video_id)
                self.download_mv(mv_source_list, title, video_id)
                print('已下载MV数量：', mv_count)
            '''


if __name__ == '__main__':
    mv = YinYueTaiSpider()
    mv.main()
