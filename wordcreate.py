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
start1 = '<div id="random_word">'
end1 = '</div>'
start2 = '<div id="random_word_definition">'
end2 = "</div>"
word = (page.split(start1))[1].split(end1)[0]
definition = (page.split(start2))[1].split(end2)[0]
f = open("word.txt", "w")
f.write(word)
d = open("definition.txt", "w")
d.write(definition)
