from django.shortcuts import render
from django.http import JsonResponse
from django.views.decorators.csrf import csrf_exempt
import json

# Create your views here.

@csrf_exempt
def rastreio(request):
    if request.method == 'POST':
        try:
            data = json.loads(request.body)

            response_data = {'status': 'sucess', 'received_data': data}
            return JsonResponse(response_data)
    
        except:
            return JsonResponse({'status': 'error', 'message': 'Invalid JSON'}, status=400)
    else:
        return JsonResponse({'status': 'error', 'message': 'Invalid method'}, status=405)
