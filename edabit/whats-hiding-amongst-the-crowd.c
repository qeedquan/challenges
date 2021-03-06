/*

A word is on the loose and now has tried to hide amongst a crowd of tall letters! Help write a function to detect what the word is, knowing the following rules:

	The wanted word is in lowercase.
	The crowd of letters is all in uppercase.
	Note that the word will be spread out amongst the random letters, but their letters remain in the same order.

Examples

detectWord("UcUNFYGaFYFYGtNUH") ➞ "cat"

detectWord("bEEFGBuFBRrHgUHlNFYaYr") ➞ "burglar"

detectWord("YFemHUFBbezFBYzFBYLleGBYEFGBMENTment") ➞ "embezzlement"

*/

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
detectword(const char *s, char *b)
{
	size_t i, j;

	for (i = j = 0; s[i]; i++) {
		if (islower(s[i]))
			b[j++] = s[i];
	}
	b[j] = '\0';

	return b;
}

void
test(const char *s, const char *r)
{
	char b[256];

	detectword(s, b);
	assert(!strcmp(b, r));
}

int
main(void)
{
	test("UcUNFYGaFYFYGtNUH", "cat");
	test("bEEFGBuFBRrHgUHlNFYaYr", "burglar");
	test("YFemHUFBbezFBYzFBYLleGBYEFGBMENTment", "embezzlement");
	test("cLXSNVVJVOJBIQRVKIZWKJOIVHXELVReLXSNVVJVOJBIQRVKIZWKJOIVHXELVRrLXSNVVJVOJBIQRVKIZWKJOIVHXELVRtLXSNVVJVOJBIQRVKIZWKJOIVHXELVRaLXSNVVJVOJBIQRVKIZWKJOIVHXELVRiLXSNVVJVOJBIQRVKIZWKJOIVHXELVRn", "certain");
	test("cUEOYCSUXVOaUEOYCSUXVOt", "cat");
	test("vJAQSZNYRQTFUHDHSDMBDPUNFQJXSXeJAQSZNYRQTFUHDHSDMBDPUNFQJXSXgJAQSZNYRQTFUHDHSDMBDPUNFQJXSXeJAQSZNYRQTFUHDHSDMBDPUNFQJXSXtJAQSZNYRQTFUHDHSDMBDPUNFQJXSXaJAQSZNYRQTFUHDHSDMBDPUNFQJXSXbJAQSZNYRQTFUHDHSDMBDPUNFQJXSXlJAQSZNYRQTFUHDHSDMBDPUNFQJXSXe", "vegetable");
	test("dATIQTJLBZFHSRXWOZQMOKZPANOUGMeATIQTJLBZFHSRXWOZQMOKZPANOUGMlATIQTJLBZFHSRXWOZQMOKZPANOUGMiATIQTJLBZFHSRXWOZQMOKZPANOUGMgATIQTJLBZFHSRXWOZQMOKZPANOUGMhATIQTJLBZFHSRXWOZQMOKZPANOUGMt", "delight");
	test("pUBOKJGODIJBSXPMTODCGHATrUBOKJGODIJBSXPMTODCGHATiUBOKJGODIJBSXPMTODCGHATcUBOKJGODIJBSXPMTODCGHATeUBOKJGODIJBSXPMTODCGHATy", "pricey");
	test("sWRRKMVJVHHZTKAQTJUQDPKHSHPOYCnWRRKMVJVHHZTKAQTJUQDPKHSHPOYCaWRRKMVJVHHZTKAQTJUQDPKHSHPOYCkWRRKMVJVHHZTKAQTJUQDPKHSHPOYCe", "snake");
	test("aJULRJHMOVLEFVJZnJULRJHMOVLEFVJZgJULRJHMOVLEFVJZlJULRJHMOVLEFVJZe", "angle");
	test("aJWCHXONGQCXGPXLZQBKEIHZWwJWCHXONGQCXGPXLZQBKEIHZWaJWCHXONGQCXGPXLZQBKEIHZWrJWCHXONGQCXGPXLZQBKEIHZWe", "aware");
	test("nNUZKGKNEVZBPQZQQLHZZPaNUZKGKNEVZBPQZQQLHZZPmNUZKGKNEVZBPQZQQLHZZPe", "name");
	test("cLBFKXYQFLLElLBFKXYQFLLEeLBFKXYQFLLEvLBFKXYQFLLEeLBFKXYQFLLEr", "clever");
	test("bDUNEPWILKUFNTRGMBRSVGAABBFCCXErDUNEPWILKUFNTRGMBRSVGAABBFCCXEaDUNEPWILKUFNTRGMBRSVGAABBFCCXEsDUNEPWILKUFNTRGMBRSVGAABBFCCXEh", "brash");
	test("fXTTJVWFCHYZMaXTTJVWFCHYZMsXTTJVWFCHYZMt", "fast");
	test("dJYPHZIRXYOLDGAQUPHIZTXJOKNoJYPHZIRXYOLDGAQUPHIZTXJOKNwJYPHZIRXYOLDGAQUPHIZTXJOKNnJYPHZIRXYOLDGAQUPHIZTXJOKNtJYPHZIRXYOLDGAQUPHIZTXJOKNoJYPHZIRXYOLDGAQUPHIZTXJOKNwJYPHZIRXYOLDGAQUPHIZTXJOKNn", "downtown");
	test("pKICNUFWFNFORlKICNUFWFNFORaKICNUFWFNFORnKICNUFWFNFORtKICNUFWFNFORs", "plants");
	test("wLAXIBDWXVPRQOOQRRTOYRODLAQHiLAXIBDWXVPRQOOQRRTOYRODLAQHnLAXIBDWXVPRQOOQRRTOYRODLAQHdLAXIBDWXVPRQOOQRRTOYRODLAQHy", "windy");
	test("sELJQETMYLTDKXYNSSOISZFPMAtELJQETMYLTDKXYNSSOISZFPMAaELJQETMYLTDKXYNSSOISZFPMArELJQETMYLTDKXYNSSOISZFPMAt", "start");
	test("wQYKDHGMNYMKUHKDeQYKDHGMNYMKUHKDt", "wet");
	test("kVOJQJIFILEHVnVOJQJIFILEHViVOJQJIFILEHVfVOJQJIFILEHVe", "knife");
	test("nBKCXNIJYJSVDoBKCXNIJYJSVDtBKCXNIJYJSVDe", "note");
	test("bOEYZAJVFYUGXQWZXrOEYZAJVFYUGXQWZXuOEYZAJVFYUGXQWZXsOEYZAJVFYUGXQWZXh", "brush");
	test("tEMVSYRPYHSZRLJNOMTYRPREIHoEMVSYRPYHSZRLJNOMTYRPREIHoEMVSYRPYHSZRLJNOMTYRPREIHtEMVSYRPYHSZRLJNOMTYRPREIHhEMVSYRPYHSZRLJNOMTYRPREIHbEMVSYRPYHSZRLJNOMTYRPREIHrEMVSYRPYHSZRLJNOMTYRPREIHuEMVSYRPYHSZRLJNOMTYRPREIHsEMVSYRPYHSZRLJNOMTYRPREIHh", "toothbrush");
	test("sWRIQGRPNHQQPSIPRoWRIQGRPNHQQPSIPRgWRIQGRPNHQQPSIPRgWRIQGRPNHQQPSIPRy", "soggy");
	test("fRBODZACXIIXHZRGKJQMDLOONTlRBODZACXIIXHZRGKJQMDLOONToRBODZACXIIXHZRGKJQMDLOONTwRBODZACXIIXHZRGKJQMDLOONTeRBODZACXIIXHZRGKJQMDLOONTrRBODZACXIIXHZRGKJQMDLOONTs", "flowers");
	test("dPWUSQZDQIHANDHEQUZBLAULSoPWUSQZDQIHANDHEQUZBLAULSlPWUSQZDQIHANDHEQUZBLAULSl", "doll");
	test("aOGSREBZUHUEJYSSBUlOGSREBZUHUEJYSSBUoOGSREBZUHUEJYSSBUoOGSREBZUHUEJYSSBUf", "aloof");
	test("aGQEAESDQIBWRUTuGQEAESDQIBWRUTsGQEAESDQIBWRUTpGQEAESDQIBWRUTiGQEAESDQIBWRUTcGQEAESDQIBWRUTiGQEAESDQIBWRUToGQEAESDQIBWRUTuGQEAESDQIBWRUTs", "auspicious");
	test("mPVIWSNGHMXHaPVIWSNGHMXHrPVIWSNGHMXHkPVIWSNGHMXHePVIWSNGHMXHt", "market");
	test("dUMIHKRZLPJFAGUKPGXHiUMIHKRZLPJFAGUKPGXHlUMIHKRZLPJFAGUKPGXHiUMIHKRZLPJFAGUKPGXHgUMIHKRZLPJFAGUKPGXHeUMIHKRZLPJFAGUKPGXHnUMIHKRZLPJFAGUKPGXHt", "diligent");
	test("sPRTRRRETBCDTtPRTRRRETBCDTrPRTRRRETBCDTiPRTRRRETBCDTpPRTRRRETBCDTePRTRRRETBCDTd", "striped");
	test("mDKXCLZDVPRNMGGFGEOZoDKXCLZDVPRNMGGFGEOZoDKXCLZDVPRNMGGFGEOZn", "moon");
	test("aQQWPQYQEEDILHYDSGQAINQZWCABYcQQWPQYQEEDILHYDSGQAINQZWCABYcQQWPQYQEEDILHYDSGQAINQZWCABYoQQWPQYQEEDILHYDSGQAINQZWCABYuQQWPQYQEEDILHYDSGQAINQZWCABYnQQWPQYQEEDILHYDSGQAINQZWCABYt", "account");
	test("sJPUQNBZOQYREGGQSYPmJPUQNBZOQYREGGQSYPeJPUQNBZOQYREGGQSYPlJPUQNBZOQYREGGQSYPlJPUQNBZOQYREGGQSYPy", "smelly");
	test("iWHDAZIAOYUDTHYYCUNBXQnWHDAZIAOYUDTHYYCUNBXQk", "ink");
	test("mOMTJYOJTLFBKGMYISFQHiOMTJYOJTLFBKGMYISFQHsOMTJYOJTLFBKGMYISFQHcOMTJYOJTLFBKGMYISFQHrOMTJYOJTLFBKGMYISFQHeOMTJYOJTLFBKGMYISFQHaOMTJYOJTLFBKGMYISFQHnOMTJYOJTLFBKGMYISFQHt", "miscreant");
	test("qFEUYWIKGXCZVXOPZKOBCKHEBuFEUYWIKGXCZVXOPZKOBCKHEBiFEUYWIKGXCZVXOPZKOBCKHEBxFEUYWIKGXCZVXOPZKOBCKHEBoFEUYWIKGXCZVXOPZKOBCKHEBtFEUYWIKGXCZVXOPZKOBCKHEBiFEUYWIKGXCZVXOPZKOBCKHEBc", "quixotic");
	test("dXKIIKPMULMUIDCSOFTJrXKIIKPMULMUIDCSOFTJaXKIIKPMULMUIDCSOFTJcXKIIKPMULMUIDCSOFTJoXKIIKPMULMUIDCSOFTJnXKIIKPMULMUIDCSOFTJiXKIIKPMULMUIDCSOFTJaXKIIKPMULMUIDCSOFTJn", "draconian");
	test("cVBMNIAWBKZCBuVBMNIAWBKZCBrVBMNIAWBKZCBiVBMNIAWBKZCBoVBMNIAWBKZCBuVBMNIAWBKZCBs", "curious");
	test("dWMZKRYZEXCEVEiWMZKRYZEXCEVEsWMZKRYZEXCEVEtWMZKRYZEXCEVEuWMZKRYZEXCEVErWMZKRYZEXCEVEbWMZKRYZEXCEVEeWMZKRYZEXCEVEd", "disturbed");
	test("lJMDJPLYPPJTAPOSeJMDJPLYPPJTAPOSaJMDJPLYPPJTAPOSn", "lean");
	test("gDTWSJJAFFHHMNMPXTAWKQOVrDTWSJJAFFHHMNMPXTAWKQOVoDTWSJJAFFHHMNMPXTAWKQOVuDTWSJJAFFHHMNMPXTAWKQOVcDTWSJJAFFHHMNMPXTAWKQOVhDTWSJJAFFHHMNMPXTAWKQOVy", "grouchy");
	test("aNHHJIPROAMxNHHJIPROAMiNHHJIPROAMoNHHJIPROAMmNHHJIPROAMaNHHJIPROAMtNHHJIPROAMiNHHJIPROAMc", "axiomatic");
	test("tXBGCUQSBNTSGZMAVNNIYOVVVAZOQKeXBGCUQSBNTSGZMAVNNIYOVVVAZOQKnXBGCUQSBNTSGZMAVNNIYOVVVAZOQKuXBGCUQSBNTSGZMAVNNIYOVVVAZOQKoXBGCUQSBNTSGZMAVNNIYOVVVAZOQKuXBGCUQSBNTSGZMAVNNIYOVVVAZOQKs", "tenuous");
	test("yVBNHOPAMPHUKGZJFATSHCZAeVBNHOPAMPHUKGZJFATSHCZAaVBNHOPAMPHUKGZJFATSHCZAr", "year");
	test("gNWUOMXIDOFQLKrNWUOMXIDOFQLKaNWUOMXIDOFQLKb", "grab");
	test("bTVORYGRQELJJOQKZWIENrTVORYGRQELJJOQKZWIENoTVORYGRQELJJOQKZWIENtTVORYGRQELJJOQKZWIENhTVORYGRQELJJOQKZWIENeTVORYGRQELJJOQKZWIENr", "brother");
	test("sYZYERJOTTELSPOSAMmYZYERJOTTELSPOSAMeYZYERJOTTELSPOSAMlYZYERJOTTELSPOSAMl", "smell");
	test("cCPHANPWHKQWLRFDBJOCKTBNUCFXeCPHANPWHKQWLRFDBJOCKTBNUCFXnCPHANPWHKQWLRFDBJOCKTBNUCFXt", "cent");
	test("rBZFHMFKHMKXEDMSuBZFHMFKHMKXEDMStBZFHMFKHMKXEDMShBZFHMFKHMKXEDMSlBZFHMFKHMKXEDMSeBZFHMFKHMKXEDMSsBZFHMFKHMKXEDMSs", "ruthless");
	test("pFGEMWBMWIHLPLVJFaFGEMWBMWIHLPLVJFnFGEMWBMWIHLPLVJFiFGEMWBMWIHLPLVJFcFGEMWBMWIHLPLVJFkFGEMWBMWIHLPLVJFy", "panicky");
	test("tIBIEPZZNNVJWMJNTUKRADYXWXZAeIBIEPZZNNVJWMJNTUKRADYXWXZAdIBIEPZZNNVJWMJNTUKRADYXWXZAiIBIEPZZNNVJWMJNTUKRADYXWXZAoIBIEPZZNNVJWMJNTUKRADYXWXZAuIBIEPZZNNVJWMJNTUKRADYXWXZAs", "tedious");

	return 0;
}
