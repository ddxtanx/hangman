import requests
def find_between( s, first, last ):
    try:
        start = s.index( first ) + len( first )
        end = s.index( last, start )
        return s[start:end]
    except ValueError,e:
        print e
        return ""

url = "http://www.randomword.com"
page = requests.get(url)
page = page.text.encode('utf8')
start = '<div id="random_word">'
end = '</div>'
value = (page.split(start))[1].split(end)[0]
f = open("word.txt", "w")
f.write(value)
