from http.server import HTTPServer, SimpleHTTPRequestHandler
import json, os

class Handler(SimpleHTTPRequestHandler):
    def do_POST(self):
        if self.path == '/append':
            length = int(self.headers['Content-Length'])
            data   = json.loads(self.rfile.read(length))
            fname  = data.get('file', '')
            content= data.get('content', '')

            # Security: sirf in 3 files mein likhne do
            allowed = ['student.txt', 'teacher.txt', 'attendance.txt']
            if fname not in allowed:
                self.send_response(403); self.end_headers(); return

            with open(fname, 'a', encoding='utf-8') as f:
                f.write(content)

            self.send_response(200)
            self.send_header('Access-Control-Allow-Origin', '*')
            self.end_headers()
            self.wfile.write(b'OK')
        else:
            self.send_response(404); self.end_headers()

    def do_OPTIONS(self):
        self.send_response(200)
        self.send_header('Access-Control-Allow-Origin', '*')
        self.send_header('Access-Control-Allow-Methods', 'POST, GET, OPTIONS')
        self.send_header('Access-Control-Allow-Headers', 'Content-Type')
        self.end_headers()

    def log_message(self, format, *args):
        pass  # console clean rakhne ke liye

if __name__ == '__main__':
    port = 8000
    os.chdir(os.path.dirname(os.path.abspath(__file__)))
    print(f"✅ Server chalu hai: http://localhost:{port}/gui.html")
    print("   Band karne ke liye Ctrl+C dabao.\n")
    HTTPServer(('', port), Handler).serve_forever()
