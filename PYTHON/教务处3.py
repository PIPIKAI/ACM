'''
目标网址：http://uia.hnist.cn/sso/login?service=http%3A%2F%2Fuia.hnist.cn%2Fj_spring_cas_security_check%3Bjsessionid%3D0EB22043AE891EECEC30B9F9254694C9.a
程序目的：登录教务处获取成绩
作者:zhongzhikai
时间：2019-7-19
'''
import selenium.webdriver
import time
driver = selenium.webdriver.Chrome()
url = "http://uia.hnist.cn/sso/login?service=http%3A%2F%2Fuia.hnist.cn%2Fj_spring_cas_security_check%3Bjsessionid%3D0EB22043AE891EECEC30B9F9254694C9.a"
driver.get(url)
time.sleep(5)
# 输入用户名和密码
username=input("输入账号")
password=input("输入密码")
driver.find_element_by_id("username").send_keys(username)
driver.find_element_by_id("password").send_keys(password)
driver.find_element_by_id("input1").click()
time.sleep(3)
driver.refresh()
time.sleep(3)
driver.find_element_by_xpath('//*[@id="sysAppsList"]/li[2]/a/img').click()
time.sleep(5)
driver.switch_to_window(driver.window_handles[1])
time.sleep(2)
driver.find_element_by_xpath('//*[@id="div_1443377"]/div[1]/i').click()
time.sleep(2)
result =driver.find_elements_by_xpath('//*[@id="2018-2019-2-1"]/table/tbody/tr')
#result=result.text
for i in result:
    print(i.text)
time.sleep(15)
driver.close()
driver.quit()
