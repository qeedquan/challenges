#!/usr/bin/env python3

"""

Motif Implies Function

As mentioned in “Translating RNA into Protein”, proteins perform every practical function in the cell.
A structural and functional unit of the protein is a protein domain: in terms of the protein's primary structure, the domain is an interval of amino acids that can evolve and function independently.

Each domain usually corresponds to a single function of the protein (e.g., binding the protein to DNA, creating or breaking specific chemical bonds, etc.).
Some proteins, such as myoglobin and the Cytochrome complex, have only one domain, but many proteins are multifunctional and therefore possess several domains.
It is even possible to artificially fuse different domains into a protein molecule with definite properties, creating a chimeric protein.

Just like species, proteins can evolve, forming homologous groups called protein families. Proteins from one family usually have the same set of domains, performing similar functions; see Figure 1.

A component of a domain essential for its function is called a motif, a term that in general has the same meaning as it does in nucleic acids, although many other terms are also used (blocks, signatures, fingerprints, etc.)
Usually protein motifs are evolutionarily conservative, meaning that they appear without much change in different species.

Proteins are identified in different labs around the world and gathered into freely accessible databases.
A central repository for protein data is UniProt, which provides detailed protein annotation, including function description, domain structure, and post-translational modifications.
UniProt also supports protein similarity search, taxonomy analysis, and literature citations.

Problem
To allow for the presence of its varying forms, a protein motif is represented by a shorthand as follows: [XY] means "either X or Y" and {X} means "any amino acid except X." For example, the N-glycosylation motif is written as N{P}[ST]{P}.

You can see the complete description and features of a particular protein by its access ID "uniprot_id" in the UniProt database, by inserting the ID number into

http://www.uniprot.org/uniprot/uniprot_id
Alternatively, you can obtain a protein sequence in FASTA format by following

http://www.uniprot.org/uniprot/uniprot_id.fasta
For example, the data for protein B5ZC00 can be found at http://www.uniprot.org/uniprot/B5ZC00.

Given: At most 15 UniProt Protein Database access IDs.

Return: For each protein possessing the N-glycosylation motif, output its given access ID followed by a list of locations in the protein string where the motif can be found.

Sample Dataset
A2Z669
B5ZC00
P07204_TRBM_HUMAN
P20840_SAG1_YEAST
Sample Output
B5ZC00
85 118 142 306 395
P07204_TRBM_HUMAN
47 115 116 382 409
P20840_SAG1_YEAST
79 109 135 248 306 348 364 402 485 501 614

Note
Some entries in UniProt have one primary (citable) accession number and some secondary numbers, appearing due to merging or demerging entries. In this problem, you may be given any type of ID. If you type the secondary ID into the UniProt query, then you will be automatically redirected to the page containing the primary ID. You can find more information about UniProt IDs here.

"""

import requests
import re

def find(code):
    try:
        response = requests.get("http://www.uniprot.org/uniprot/%s.fasta" % code)
        data = response.content.decode("utf-8")
        lines = data.split('\n')
        fasta = "".join(lines[1:])
        
        matches = re.finditer(r"(?=N[^P][ST][^P])", fasta)
        indices = []
        for match in matches:
            indices.append(match.start() + 1)

        if len(indices) > 0:
            print(code)
            print(indices)
    except:
        pass

def main():
    find("A2Z669")
    find("B5ZC00")
    find("P07204_TRBM_HUMAN")
    find("P20840_SAG1_YEAST")

main()
