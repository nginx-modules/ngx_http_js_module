require('cascade.js')
require('test.js')
require('test-tool.js')
require('tests.js')
require('url-encode.js')
require('regexp-escape.js')

Test.Inspector.prototype.sep = ' '
Test.Inspector.prototype.indc = ''

var NginxTests = {}
var NginxDemos = {}

;(function(){

var memory = []

var myName = 'Handler', Me =
{
	run: function (r)
	{
		var m = /([^\/]+)$/.exec(r.uri)
		
		if (m)
		{
			var method = m[1].replace(/-(\w)/g, function (m) { return m[1].toUpperCase() })
			
			if (NginxTests[method])
				return NginxTests[method](r)
			else
				r.sendString('no such method')
		}
		else
			r.sendString('error in uri')
		
		return Nginx.OK
	},
	
	demo: function (r)
	{
		var m = /([^\/]+)$/.exec(r.uri)
		
		if (m)
		{
			var method = m[1].replace(/-(\w)/g, function (m) { return m[1].toUpperCase() })
			
			if (NginxDemos[method])
				return NginxDemos[method](r)
			else
				r.sendString('no such method')
		}
		else
			r.sendString('error in uri')
		
		return Nginx.OK
	}
}

Me.className = myName
self[myName] = Me

})();

require('tests/nginx-object.js')
require('tests/request-object.js')
require('tests/request-body.js')
require('tests/request-body-plain.js')
require('tests/request-body-file.js')
require('tests/request-body-discard.js')
require('tests/file.js')
require('tests/dir.js')
require('tests/process-cycle.js')
require('tests/request-cookies.js')
require('tests/request-headers-in.js')
require('tests/request-headers-in-set-get.js')
require('tests/request-headers-out-set-get.js')
require('tests/variable-set.js')
require('tests/request-variables.js')
require('tests/standart-classes.js')
require('tests/subrequests.js')
require('tests/subrequest-headers-out.js')
require('tests/subrequest-headers-in.js')
require('tests/request-sendfile.js')
require('tests/request-redirect.js')
require('tests/request-send-string.js')
require('tests/request-response-codes.js')
require('tests/access.js')

require('demos/request-headers-out.js')
require('demos/delayed-output.js')
require('demos/delayed-output-2.js')
require('demos/return-an-error.js')
require('demos/return-error-500.js')
require('demos/subrequest-long.js')
