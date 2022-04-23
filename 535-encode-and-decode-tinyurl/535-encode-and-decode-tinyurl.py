class Codec:
    code = "http://tinyurl.com/4e9iAk"
    def encode(self, longUrl: str) -> str:
        self.url = longUrl
        return Codec.code

    def decode(self, shortUrl: str) -> str:
        return self.url

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))